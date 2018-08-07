/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_and_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:23:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/07 09:13:20 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_diff(t_frame *frame, char *str)
{
	int				len;

	len = ft_strlen(str);
	return (frame->len_user - len);
}

static void			user(t_frame *frame, t_args *args)
{
	if (frame->option.g)
		return ;
	ft_putstr(args->data.user);
	print_spaces(get_diff(frame, args->data.user) + 2);
}

static void			group(t_frame *frame, t_args *args)
{
	if (frame->option.o)
		return ;
	ft_putstr(args->data.group);
	print_spaces(get_diff(frame, args->data.user) + 2);
}

void				user_and_group(t_frame *frame, t_args *args)
{
	user(frame, args);
	group(frame, args);
	if (frame->option.g && frame->option.o)
		ft_printf("  ");
}
