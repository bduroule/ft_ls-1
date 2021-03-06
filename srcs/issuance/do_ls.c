/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:47:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/31 15:32:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

static bool			read_directory(t_read_dir *read_dir)
{
	if ((read_dir->frame->option.up_a && (ft_strcmp(read_dir->file->d_name, ".")
					&& ft_strcmp(read_dir->file->d_name, "..")))
			|| (read_dir->frame->option.a && read_dir->file->d_name[0] == '.')
			|| (read_dir->file->d_name[0] != '.'))
	{
		if (!(read_dir->tmp = create_args()))
		{
			free_args(read_dir->frame, &read_dir->head);
			return (false);
		}
		path(read_dir->frame, read_dir->tmp, read_dir->args->data.path,
				read_dir->file->d_name);
		if (!read_dir->head)
			read_dir->head = read_dir->tmp;
		else
			read_dir->last_args->next = read_dir->tmp;
		read_dir->last_args = read_dir->tmp;
	}
	return (true);
}

static t_args		*get_directory_contents(t_frame *frame, t_args *args)
{
	t_read_dir		read_dir;

	read_dir.frame = frame;
	read_dir.args = args;
	read_dir.head = NULL;
	if (!(read_dir.directory = opendir(read_dir.args->data.path)))
	{
		ft_printf("ft_ls: %s: Permission denied\n", read_dir.args->data.str);
		return (NULL);
	}
	while ((read_dir.file = readdir(read_dir.directory)))
	{
		if (!read_directory(&read_dir))
			return (NULL);
	}
	closedir(read_dir.directory);
	return (read_dir.head);
}

static void			check_headers(t_frame *frame, t_args *head)
{
	t_args			*args;

	args = head;
	while (args && !frame->headers)
	{
		if (frame->option.up_r && args->data.dir && !frame->option.d)
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
	if (!(head = get_directory_contents(frame, args)))
		return ;
	frame->current_args = head;
	get_attributes(frame);
	sort(frame);
	head = frame->current_args;
	loop_valid_dir(frame, head);
	if (frame->option.up_r)
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
