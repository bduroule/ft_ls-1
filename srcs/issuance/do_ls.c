/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:47:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 20:48:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

void				do_ls(t_frame *frame, t_args *args)
{
	t_args			*head;
	t_args			*tmp;
	t_args			*last_args;
	DIR				*directory;
	struct dirent	*dir;

	head = NULL;
	if (!(directory = opendir(args->data.str)))
	{
		ft_printf("ls: %s: Permission denied\n", args->data.str);
		return ;
	}
	while ((dir = readdir(directory)))
	{
		tmp = create_args(frame);
		tmp->data.str = dir->d_name;
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
