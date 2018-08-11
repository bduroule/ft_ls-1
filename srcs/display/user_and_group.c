/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_and_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:23:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:12:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			user(t_frame *frame, t_args *args)
{
	if (frame->option.g)
		return ;
	ft_putstr(args->data.user);
	print_spaces(get_diff(frame, args->data.user, 0, LEN_USER) + 2);
}

static void			group(t_frame *frame, t_args *args)
{
	if (frame->option.o)
		return ;
	ft_putstr(args->data.group);
	print_spaces(get_diff(frame, args->data.group, 0, LEN_GROUP) + 2);
}

void				user_and_group(t_frame *frame, t_args *args)
{
	user(frame, args);
	group(frame, args);
	if (frame->option.g && frame->option.o)
		ft_printf("  ");
}
