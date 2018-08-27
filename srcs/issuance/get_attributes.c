/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:25:28 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/27 20:13:51 by dhojt            ###   ########.fr       */
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
	else if ((TYPE_SOCK & type) == TYPE_SOCK)
		args->data.sock = 1;
	else if ((TYPE_REG & type) == TYPE_REG)
		args->data.reg = 1;
	else if ((TYPE_WHT & type) == TYPE_WHT)
		args->data.wht = 1;
	else if ((TYPE_IFO & type) == TYPE_IFO)
		args->data.ifo = 1;
	else if ((TYPE_CHR & type) == TYPE_CHR)
		args->data.chr = 1;
	else if ((TYPE_DIR & type) == TYPE_DIR)
		args->data.dir = 1;
	if ((TYPE_BLK & type) == TYPE_BLK)
		args->data.blk = 1;
}

static void			get_user_group(t_frame *frame, t_args *args, struct stat *f)
{
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = getpwuid(f->st_uid)))
		(args->data.user = ft_strdup(passwd->pw_name));//DONE
	else
		args->data.user = ft_itoa(f->st_uid);//DONE
	if (!args->data.user)
		args->data.user = frame->malloc_failed;
	if ((group = getgrgid(f->st_gid)))
		args->data.group = ft_strdup(group->gr_name);//DONE
	else
		args->data.group = ft_itoa(f->st_gid);//DONE
	if (!args->data.group)
		args->data.group = frame->malloc_failed;
}

void				read_f(t_frame *frame, t_args *args, struct stat *f)
{
	frame->total_blocks += f->st_blocks;
	args->data.ino = f->st_ino;
	args->data.mode = f->st_mode;
	args->data.type = f->st_mode;
	args->data.links = f->st_nlink;
	get_user_group(frame, args, f);
	args->data.rdev = f->st_rdev;
	args->data.size = f->st_size;
	args->data.c_time = f->st_ctimespec.tv_sec;
	args->data.t_time = f->st_mtimespec.tv_sec;
	args->data.u_time = f->st_atimespec.tv_sec;
	args->data.U_time = f->st_birthtimespec.tv_sec;
	get_type(args);
}


void				get_attributes(t_frame *frame)
{
	t_args			*args;
	struct stat		f;

	args = frame->current_args;
	while (args)
	{
		if (!lstat(args->data.path, &f))
			read_f(frame, args, &f);
		else
			args->data.no_file = 1;
		args = args->next;
	}
}
