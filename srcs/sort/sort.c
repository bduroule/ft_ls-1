/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:13:10 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 11:43:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			swap(t_frame *frame) //ALPHABETICAL
{
	t_data			tmp;
	if (ft_strcmp(frame->track->data.str, frame->track->next->data.str) > 0)
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
	frame->head = frame->current_args;
	// Chose sorting method
	do_sort(frame);
	frame->current_args = frame->head;
}
