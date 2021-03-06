/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:10:39 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/31 16:31:34 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_time(t_frame *frame)
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
	if (frame->option.up_u)
	{
		if (frame->track->data.up_u_time < frame->track->next->data.up_u_time)
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
