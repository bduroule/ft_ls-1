/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issuance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:55:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/20 12:25:06 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				issuance(t_frame *frame)
{
	frame->sort = frame->args;
	get_attributes(frame);
	sort(frame);
	if (frame)
		;
}
