/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:51:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 19:29:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			do_config(t_frame *frame)
{
	if (COLOUR)
		frame->option.G = 1;
	if (COLUMN)
		frame->option.x = 1;
	if (frame->option.d)
		frame->option.R = 0;
	if (frame->option.f)
		frame->option.a = 1;
	if (frame->option.S)
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
