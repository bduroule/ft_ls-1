/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_t_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 23:14:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 23:14:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_time_t_r(t_frame *frame)
{
	if (frame->track->data.t_time > frame->track->next->data.t_time)
		return (true);
	return (false);
}
