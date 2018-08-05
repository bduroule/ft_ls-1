/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:56:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 23:16:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			sort_reverse(t_frame *frame)
{
	if (frame->option.S)
		frame->sort_function = &sort_size_r;
	else if (frame->option.t)
		frame->sort_function = &sort_time_t_r;
	else
		frame->sort_function = NULL;
}
	
static void			sort_normal(t_frame *frame)
{
	if (frame->option.S)
		frame->sort_function = &sort_size;
	else if (frame->option.t)
		frame->sort_function = &sort_time_t;
	else
		frame->sort_function = NULL;
}
	
void				assign_sort(t_frame *frame)
{
	if (!frame->option.r)
		sort_normal(frame);
	else
		sort_reverse(frame);
}
