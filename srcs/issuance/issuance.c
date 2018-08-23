/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issuance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:55:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/23 12:17:48 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			distribution(t_frame *frame)
{
	loop_no_file(frame);
	loop_files(frame);
	loop_dirs(frame);
}

static void			check_headers(t_frame *frame)
{
	t_args			*args;
	int				headers;
	int				not_dir;

	args = frame->args;
	headers = 0;
	not_dir = 0;
	while (args && !frame->headers)
	{
		if (!not_dir && !args->data.dir && !frame->option.d)
			not_dir++;
		if (args->data.dir && !frame->option.d)
			headers++;
		if (headers > 1 || (headers && not_dir))
			frame->headers = 1;
		args = args->next;
	}
}

void				issuance(t_frame *frame)
{
	frame->current_args = frame->args;
	get_attributes(frame);
	sort(frame);
	frame->args = frame->current_args;
	check_headers(frame);
	distribution(frame);
}
