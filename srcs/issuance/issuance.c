/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issuance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:55:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 16:41:15 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
static bool			is_file(t_args *args)
{
	if (args->data.type >> 15 != 1)
		return (true);
	return (false);
}

static void			distribution(t_frame *frame)
{
	while (frame->args)
	{
		frame->exec_args = frame->args;
		if (is_file(frame->exec_args))
			display(frame, frame->exec_args);
		frame->args = frame->args->next;
	}
}

void				issuance(t_frame *frame)
{
	frame->current_args = frame->args;
	get_attributes(frame);
	sort(frame);
	frame->args = frame->current_args;
	distribution(frame);
}
