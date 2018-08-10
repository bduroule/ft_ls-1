/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:24:47 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 14:44:32 by dhojt            ###   ########.fr       */
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
		if ((!head->data.dir || frame->option.d) && !head->data.no_file)
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
}

void				loop_files(t_frame *frame)
{
	t_args			*args;

	args = frame->args;
	get_column_widths(frame, args);
	while (args)
	{
		if ((!args->data.dir || frame->option.d) && !args->data.no_file)
			display(frame, args);
		args = args->next;
	}
	if (frame->option.N && frame->items_to_display)
		ft_printf(NUM_FILES, frame->items_to_display);
}
