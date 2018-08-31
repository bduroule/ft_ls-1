/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:51:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/31 16:27:33 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			do_config(t_frame *frame)
{
	if (COLOUR)
		frame->option.up_g = 1;
	if (COLUMN)
		frame->option.x = 1;
	if (frame->option.d)
		frame->option.up_r = 0;
	if (frame->option.f)
		frame->option.a = 1;
	if (frame->option.up_s)
		frame->option.t = 0;
	if (frame->option.l)
		frame->option.x = 0;
	if (frame->option.one)
	{
		frame->option.l = 0;
		frame->option.x = 0;
	}
}

void				config_options(t_frame *frame)
{
	do_config(frame);
	assign_sort(frame);
}
