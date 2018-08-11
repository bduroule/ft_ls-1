/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_number_of_columns.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:29:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 13:30:08 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calculate_number_of_columns(t_frame *frame)
{
	int				column_width;

	column_width = frame->len_file_name + 1;
	if (frame->option.i)
		column_width += frame->len_ino + 1;
	frame->number_of_columns = frame->width / column_width;
}
