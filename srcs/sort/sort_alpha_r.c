/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alpha_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 22:41:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/23 22:41:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_alpha_r(t_frame *frame)
{
	if (ft_strcmp(frame->track->data.str, frame->track->next->data.str) < 0)
		return (true);
	return (false);
}
