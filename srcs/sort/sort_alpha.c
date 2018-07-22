/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 11:59:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 12:00:43 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					sort_alpha(t_frame *frame)
{
	return (ft_strcmp(frame->track->data.str, frame->track->next->data.str) > 0);
}
