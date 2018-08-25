/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:47:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/24 17:21:38 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

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
			if (!(tmp = create_args()))//DONE
			{
				free_args(frame, &head);
				return (NULL);
			}
			path(frame, tmp, args->data.path, file->d_name);
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

static void			check_headers(t_frame *frame, t_args *head)
{
	t_args			*args;
	
	args = head;
	while (args && !frame->headers)
	{
		if (frame->option.R && args->data.dir && !frame->option.d)
			frame->headers = 1;
		args = args->next;
	}
}

void				do_ls(t_frame *frame, t_args *args)
{
	t_args			*head;
	t_args			*tmp;

	check_headers(frame, args);
	print_path(frame, args, true);
	if (!(head = read_directory(frame, args)))//DONE
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
			if (tmp->data.dir && ft_strcmp(tmp->data.str, ".")
						&& ft_strcmp(tmp->data.str, ".."))
				do_ls(frame, tmp);
			tmp = tmp->next;
		}
	}
	free_args(frame, &head);
}
