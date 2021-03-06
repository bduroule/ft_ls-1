/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 19:26:22 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/31 14:57:53 by dhojt            ###   ########.fr       */
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
	bool			(*tmp)(struct s_frame *frame);

	if (frame->option.f)
		return ;
	tmp = frame->sort_function;
	if (!frame->option.r)
		frame->sort_function = &sort_alpha;
	else
		frame->sort_function = &sort_alpha_r;
	frame->head = frame->current_args;
	do_sort(frame);
	frame->sort_function = tmp;
	if (tmp)
		do_sort(frame);
	frame->current_args = frame->head;
}
