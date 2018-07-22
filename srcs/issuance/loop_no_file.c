/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_no_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:18:39 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 17:21:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				loop_no_file(t_frame *frame)
{
	t_args			*args;

	args = frame->args;
	while (args)
	{
		if (args->data.no_file)
			no_file(frame, args);
		args = args->next;
	}
}
