/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_valid_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 20:03:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/27 20:20:59 by dhojt            ###   ########.fr       */
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
	frame->total_blocks = 0;
	head = args;
	while (head)
	{
		if (!head->data.no_file)
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

static void			do_loop(t_frame *frame, t_args *args, int *position_on_row)
{
	while (args)
	{
		if (!args->data.no_file)
		{
			display(frame, args);
			*position_on_row += 1;
			if (*position_on_row >= frame->number_of_columns)
			{
				ft_putchar('\n');
				*position_on_row = 0;
			}
			else if (!frame->option.x)
				ft_putchar('\n');
		}
		args = args->next;
	}
}

void				loop_valid_dir(t_frame *frame, t_args *head)
{
	t_args			*args;
	int				position_on_row;

	position_on_row = 0;
	if (frame->option.d)
		return ;
	args = head;
	if (frame->option.l)
		ft_printf("total %d\n", frame->total_blocks);
	get_column_widths(frame, head);
	calculate_number_of_columns(frame);
	do_loop(frame, args, &position_on_row);
	if (position_on_row && frame->option.x)
		ft_putchar('\n');
	if (frame->option.N)
		ft_printf(NUM_FILES, frame->items_to_display);
}
