/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:43:03 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 20:43:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_size_r(t_frame *frame)
{
	if (frame->track->data.size > frame->track->next->data.size)
		return (true);
	return (false);
}
