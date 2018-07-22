/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:47:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 23:55:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

static void			get_path(t_frame *frame, t_args *args, char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	args->data.str = name;
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		error_exit(frame, "Malloc Failed [new_path]");
	tmp = new_path;
	while (path && *path)
		*(tmp ++) = *(path ++);
	*(tmp++) = '/';
	while (name && *name)
		*(tmp++) = *(name++);
	args->data.path = new_path;
}

void				do_ls(t_frame *frame, t_args *args)
{
	t_args			*head;
	t_args			*tmp;
	t_args			*last_args;
	DIR				*directory;
	struct dirent	*dir;

	head = NULL;
	if (!(directory = opendir(args->data.path)))
	{
		ft_printf("ls: %s: Permission denied\n", args->data.str);
		return ;
	}
	while ((dir = readdir(directory)))
	{
		tmp = create_args(frame);
		get_path(frame, tmp, args->data.path, dir->d_name);
		tmp->data.str = dir->d_name;
		tmp->data.path = args->data.path;
		if (!head)
			head = tmp;
		else
			last_args->next = tmp;
		last_args = tmp;
	}
	closedir(directory);
	frame->current_args = head;
	get_attributes(frame);
	sort(frame);
	head = frame->current_args;
	loop_valid_dir(frame, head);
}
