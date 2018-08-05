/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:10:39 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 21:11:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_time_t(t_frame *frame)
{
	if (frame->track->data.t_time > frame->track->next->data.t_time)
		return (true);
	return (false);
}
