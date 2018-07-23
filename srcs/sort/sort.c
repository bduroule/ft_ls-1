/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:13:10 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/23 21:56:33 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			swap(t_frame *frame)
{
	t_data			tmp;
	if (frame->sort_function(frame))
	{
		tmp = frame->track->data;
		frame->track->data = frame->track->next->data;
		frame->track->next->data = tmp;
		return (1);
	}
	return (0);
}

static void			do_sort(t_frame *frame)
{
	int				sorted;

	while (1)
	{
		frame->track = frame->head;
		sorted = 1;
		while (frame->track && frame->track->next)
		{
			if (swap(frame))
				sorted = 0;
			frame->track = frame->track->next;
		}
		if (sorted)
			break ;
	}
}

void				sort(t_frame *frame)
{
	if (frame->option.f)
		return ;
	frame->head = frame->current_args;
	do_sort(frame);
	frame->current_args = frame->head;
}
