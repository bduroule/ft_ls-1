/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:56:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 19:59:37 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				assign_sort(t_frame *frame)
{
	if (frame->option.r)
		frame->sort_function = &sort_alpha_r;
	else
		frame->sort_function = &sort_alpha;
}
