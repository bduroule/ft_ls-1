/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:25:28 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/21 13:51:45 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>

void				get_attributes(t_frame *frame)
{
	t_args			*args;
	struct stat		the_file;

	args = frame->current_args;
	while (args)
	{
		if (!stat(args->str, &the_file)) //check for sym links
		{
			args->ino = the_file.st_ino;
			args->type = the_file.st_mode;
			args->links = 0; //Discover hard links
			args->user = getpwuid(the_file.st_uid)->pw_name;
			args->group = getgrgid(the_file.st_gid)->gr_name;
			args->size = the_file.st_size;
			args->c_time = the_file.st_ctimespec.tv_sec;
			args->t_time = the_file.st_mtimespec.tv_sec;
			args->u_time = the_file.st_atimespec.tv_sec;
			args->U_time = the_file.st_birthtimespec.tv_sec;
		}
		else
			args->no_file = 1;
		args = args->next;
	}
	args = frame->current_args;
	while (args)
	{
		if (args->no_file)
			ft_printf("ft_ls: %s: No such file or directory\n", args->str);
		args = args->next;
	}
	args = frame->current_args;
	while (args)
	{
		if (!args->no_file)
		ft_printf("%d  %-7o %s  %s %8d  %d  %-15.15s \n", args->ino, args->type, args->user, args->group, args->size, args->t_time, args->str);
		args = args->next;
	}

}
