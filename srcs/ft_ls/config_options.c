/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:51:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/19 23:07:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				config_options(t_frame *frame)
{
	if (frame->option.a)
		frame->option.A = 0;
	if (frame->option.d)
		frame->option.R = 0;
	if (frame->option.f)
		frame->option.a = 1;
	if (frame->option.S)
		frame->option.t = 0;
	if (!frame->option.t)
	{
		frame->option.u = 0;
		frame->option.c = 0;
	}
	if (frame->option.one)
		frame->option.l = 0;
}
