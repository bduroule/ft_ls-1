/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:25:28 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/19 22:11:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>

static void			get_sym_path(t_args *args)
{
	int				len;
	t_data			*data;

	data = &args->data;
	if ((len = readlink(data->path, data->sym_path, RL_BUFSIZE)) != -1)
		data->sym_path[len] = '\0';
}

static void			get_type(t_args *args)
{
	int				type;

	type = args->data.type;
	if ((TYPE_LNK & type) == TYPE_LNK)
	{
		args->data.lnk = 1;
		get_sym_path(args);
	}
	else if ((TYPE_REG & type) == TYPE_REG)
		args->data.reg = 1;
	else if ((TYPE_SOCK & type) == TYPE_SOCK)
		args->data.sock = 1;
	else if ((TYPE_WHT & type) == TYPE_WHT)
		args->data.wht = 1;
	else if ((TYPE_IFO & type) == TYPE_IFO)
		args->data.ifo = 1;
	else if ((TYPE_CHR & type) == TYPE_CHR)
		args->data.chr = 1;
	else if ((TYPE_DIR & type) == TYPE_DIR)
		args->data.dir = 1;
	else if ((TYPE_BLK & type) == TYPE_BLK)
		args->data.blk = 1;
}

void				get_attributes(t_frame *frame)
{
	t_args			*args;
	struct stat		the_file;
	struct passwd	*passwd;
	struct group	*group;

	args = frame->current_args;
	while (args)
	{
		if (!lstat(args->data.path, &the_file)) //check for sym links
		{
			args->data.ino = the_file.st_ino;
			args->data.type = the_file.st_mode;
			args->data.links = the_file.st_nlink;
			if ((passwd = getpwuid(the_file.st_uid)))
				args->data.user = ft_strdup(passwd->pw_name);//Careful
			else
				args->data.user = ft_itoa(the_file.st_uid);//Careful
			if ((group = getgrgid(the_file.st_gid)))
				args->data.group = ft_strdup(group->gr_name);//Careful
			else
				args->data.group = ft_itoa(the_file.st_gid);//Careful
			args->data.size = the_file.st_size;
			args->data.c_time = the_file.st_ctimespec.tv_sec;
			args->data.t_time = the_file.st_mtimespec.tv_sec;
			args->data.u_time = the_file.st_atimespec.tv_sec;
			args->data.U_time = the_file.st_birthtimespec.tv_sec;
			get_type(args);
		}
		else
			args->data.no_file = 1;
		args = args->next;
	}
}
