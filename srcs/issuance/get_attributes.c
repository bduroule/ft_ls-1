/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:25:28 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/20 17:56:54 by dhojt            ###   ########.fr       */
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
		stat(args->str, &the_file);//protect  |  check for sym links
		args->type = the_file.st_mode;
		args->user = getpwuid(the_file.st_uid)->pw_name;
		args->group = getgrgid(the_file.st_gid)->gr_name;
		args->size = the_file.st_size;
		ft_printf("%15.15s Mode: %o (%s | %s) %d bytes\n", args->str, args->type, args->user, args->group, args->size);
		args = args->next;
	}
}
