/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:10:39 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 12:33:00 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_time_t(t_frame *frame)
{
	if (frame->option.c)
	{
		if (frame->track->data.c_time < frame->track->next->data.c_time)
			return (true);
		return (false);
	}
	if (frame->option.u)
	{
		if (frame->track->data.u_time < frame->track->next->data.u_time)
			return (true);
		return (false);
	}
	if (frame->option.U)
	{
		if (frame->track->data.U_time < frame->track->next->data.U_time)
			return (true);
		return (false);
	}
	else
	{
		if (frame->track->data.t_time < frame->track->next->data.t_time)
			return (true);
		return (false);
	}
}
