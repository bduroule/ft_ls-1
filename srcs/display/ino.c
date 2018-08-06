/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ino.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:40:13 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 11:41:28 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_diff(t_frame *frame, t_args *args)
{
	int				len;
	long long		num;

	len = 1;
	num = args->data.ino;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (frame->len_ino - len);
}

void				ino(t_frame *frame, t_args *args)
{
	if (!frame->option.i)
		return ;
	print_spaces(get_diff(frame, args));
	ft_printf("%lld ", args->data.ino);
}
