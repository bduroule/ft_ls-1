/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:56:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 20:08:52 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			sort_reverse(t_frame *frame)
{
		frame->sort_function = &sort_alpha_r;
}
	
static void			sort_normal(t_frame *frame)
{
		frame->sort_function = &sort_alpha;
}
	
void				assign_sort(t_frame *frame)
{
	if (!frame->option.r)
		sort_normal(frame);
	else
		sort_reverse(frame);
}
