/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:24:47 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/31 15:32:26 by dhojt            ###   ########.fr       */
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

static void			display_file(t_frame *frame, t_args *args,
		int *position_on_row)
{
	print_path(frame, args, false);
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

void				loop_files(t_frame *frame)
{
	t_args			*args;
	int				position_on_row;

	position_on_row = 0;
	args = frame->args;
	get_column_widths(frame, args);
	calculate_number_of_columns(frame);
	while (args)
	{
		if ((!args->data.dir || frame->option.d) && !args->data.no_file)
			display_file(frame, args, &position_on_row);
		args = args->next;
	}
	if (position_on_row && frame->option.x)
		ft_putchar('\n');
	if (frame->option.up_n && frame->items_to_display)
		ft_printf(NUM_FILES, frame->items_to_display);
}
