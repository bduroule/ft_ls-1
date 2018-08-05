/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:23:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 01:32:24 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_diff(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.user);
	return (frame->len_user - len);
}

void				user(t_frame *frame, t_args *args)
{
	ft_putstr(args->data.user);
	print_spaces(get_diff(frame, args) + 2);
}
