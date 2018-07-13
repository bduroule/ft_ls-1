/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:54:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/14 01:19:15 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_options(t_frame *frame)
{
	//Handle bad options
	long			one;
	long			option_data;

	one = 1;
	option_data = options(frame->argv);
	frame->option.a = (option_data & (one << ('a' - 97))) ? 1 : 0;
	frame->option.d = (option_data & (one << ('d' - 97))) ? 1 : 0;
}
