/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:13:10 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/21 18:23:22 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			swap(t_args *track) //ALPHABETICAL
{
	t_data			tmp;
	if (ft_strcmp(track->data.str, track->next->data.str) > 0)
	{
		tmp = track->data;
		track->data = track->next->data;
		track->next->data = tmp;
		ft_putstr("SWAP\n");
		return (1);
	}
	return (0);
}

static void			do_sort(t_args *head)
{
	int				sorted;
	t_args			*track;

	while (1)
	{
		track = head;
		sorted = 1;
		while (track && track->next)
		{
			if (swap(track))
				sorted = 0;
			track = track->next;
		}
		if (sorted)
			break ;
	}
}

void				sort(t_frame *frame)
{
	t_args			*head;

	head = frame->current_args;
	// Chose sorting method
	do_sort(head);
	frame->current_args = head;
}
