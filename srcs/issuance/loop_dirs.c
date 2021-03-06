/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:32:15 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/07 13:38:31 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				loop_dirs(t_frame *frame)
{
	t_args			*args;

	if (frame->option.d)
		return ;
	args = frame->args;
	while (args)
	{
		if (args->data.dir && !args->data.no_file)
			do_ls(frame, args);
		args = args->next;
	}
}
