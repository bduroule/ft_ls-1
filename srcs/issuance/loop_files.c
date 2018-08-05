/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:24:47 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 23:42:49 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				loop_files(t_frame *frame)
{
	t_args			*args;

	args = frame->args;
	get_column_widths(frame, args);
	while (args)
	{
		if (is_file(args) && !args->data.no_file)
			display(frame, args);
		args = args->next;
	}
}
