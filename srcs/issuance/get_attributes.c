/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:25:28 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/23 16:14:35 by dhojt            ###   ########.fr       */
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
		if (!stat(args->data.path, &the_file)) //check for sym links
		{
			args->data.ino = the_file.st_ino;
			args->data.type = the_file.st_mode;
			args->data.links = the_file.st_nlink;
			args->data.user = getpwuid(the_file.st_uid)->pw_name;
			args->data.group = getgrgid(the_file.st_gid)->gr_name;
			args->data.size = the_file.st_size;
			args->data.c_time = the_file.st_ctimespec.tv_sec;
			args->data.t_time = the_file.st_mtimespec.tv_sec;
			args->data.u_time = the_file.st_atimespec.tv_sec;
			args->data.U_time = the_file.st_birthtimespec.tv_sec;
		}
		else
			args->data.no_file = 1;
		args = args->next;
	}
}
