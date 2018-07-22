/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:25:28 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/23 00:10:39 by dhojt            ###   ########.fr       */
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
	t_data			*data;
	struct stat		the_file;

	args = frame->current_args;
	while (args)
	{
		data = &args->data;
		if (!stat(data->path, &the_file)) //check for sym links
		{
			data->ino = the_file.st_ino;
			data->type = the_file.st_mode;
			data->links = 0; //Discover hard links
			data->user = getpwuid(the_file.st_uid)->pw_name;
			data->group = getgrgid(the_file.st_gid)->gr_name;
			data->size = the_file.st_size;
			data->c_time = the_file.st_ctimespec.tv_sec;
			data->t_time = the_file.st_mtimespec.tv_sec;
			data->u_time = the_file.st_atimespec.tv_sec;
			data->U_time = the_file.st_birthtimespec.tv_sec;
		}
		else
			data->no_file = 1;
		args = args->next;
	}
}
