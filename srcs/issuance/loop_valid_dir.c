/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_valid_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 20:03:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 13:55:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** There is a similar function to get column widths in loop_files
*/

static void			get_column_widths(t_frame *frame, t_args *args)
{
	t_args			*head;

	frame->len_ino = 0;
	frame->len_links = 0;
	frame->len_user = 0;
	frame->len_group = 0;
	frame->len_size = 0;
	frame->len_file_name = 0;
	frame->items_to_display = 0;
	head = args;
	while (head)
	{
		if (!args->data.no_file)
		{
			if (frame->option.i)
				calc_len_ino(frame, head);
			calc_len_links(frame, head);
			calc_len_user(frame, head);
			calc_len_group(frame, head);
			calc_len_size(frame, head);
			calc_len_file_name(frame, head);
			frame->items_to_display++;
		}
		head = head->next;
	}
	ft_printf("FILES: %d\n", frame->items_to_display);
}

void				loop_valid_dir(t_frame *frame, t_args *head)
{
	t_args			*args;

	if (frame->option.d)
		return ;
	args = head;
	get_column_widths(frame, head);
	while (args)
	{
		display(frame, args);
		args = args->next;
	}
}
