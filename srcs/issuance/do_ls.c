/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:47:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/07 08:31:04 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

static void			get_path(t_frame *frame, t_args *args, char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	if(!(args->data.str = ft_strdup(name)))
		error_exit(frame, "Malloc Failed [new_name]");// Handle carefully (recurse)
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		error_exit(frame, "Malloc Failed [new_path]");// Handle carefully (recurse)
	tmp = new_path;
	while (path && *path)
		*(tmp ++) = *(path ++);
	*(tmp++) = '/';
	while (name && *name)
		*(tmp++) = *(name++);
	args->data.path = new_path;
}

static t_args		*read_directory(t_frame *frame, t_args *args)
{
	t_args			*tmp;
	t_args			*head;
	t_args			*last_args;
	DIR				*directory;
	struct dirent	*file;

	head = NULL;
	if (!(directory = opendir(args->data.path)))
	{
		ft_printf("ft_ls: %s: Permission denied\n", args->data.str);
		return (NULL);
	}
	while ((file = readdir(directory)))
	{
		if ((frame->option.A && (ft_strcmp(file->d_name, ".")
						&& ft_strcmp(file->d_name, "..")))
				|| (frame->option.a && file->d_name[0] == '.')
				|| (file->d_name[0] != '.'))
		{
			tmp = create_args(frame); //Malloc protection
			get_path(frame, tmp, args->data.path, file->d_name);
			if (!head)
				head = tmp;
			else
				last_args->next = tmp;
			last_args = tmp;
		}
	}
	closedir(directory);
	return (head);
}

void				do_ls(t_frame *frame, t_args *args)
{
	t_args			*head;
	t_args			*tmp;

	ft_printf("\n%s:\n", args->data.path);
	if(!(head = read_directory(frame, args)))
		return ;
	frame->current_args = head;
	get_attributes(frame);
	sort(frame);
	head = frame->current_args;
	loop_valid_dir(frame, head);
	if (frame->option.R)
	{
		tmp = head;
		while (tmp)
		{
			if (!is_file(tmp) && ft_strcmp(tmp->data.str, ".")
						&& ft_strcmp(tmp->data.str, ".."))
				do_ls(frame, tmp);
			tmp = tmp->next;
		}
	}
	//free head
}
