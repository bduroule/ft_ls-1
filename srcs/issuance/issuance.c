/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issuance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:55:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/23 11:41:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			distribution(t_frame *frame)
{
	loop_no_file(frame);
	loop_files(frame);
	loop_dirs(frame);
}

static void			get_headers(t_frame *frame)
{
	t_args			*args;

	args = frame->args;
	while (args && !frame->headers)
	{
		if (args->data.dir && !frame->option.d)
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
	get_headers(frame);
	distribution(frame);
}
