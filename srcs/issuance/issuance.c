/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issuance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:55:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/20 12:46:23 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			distribution(t_frame *frame)
{
	while (frame->args)
	{
		do_ls(frame);
		frame->args = frame->args->next;
	}
}

void				issuance(t_frame *frame)
{
	frame->sort = frame->args;
	get_attributes(frame);
	sort(frame);
	frame->args = frame->sort;
	distribution(frame);
}
