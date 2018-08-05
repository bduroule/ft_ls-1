/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:44:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 01:08:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_diff(t_frame *frame, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->data.links;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (frame->len_links - len);
}

void				links(t_frame *frame, t_args *args)
{
	print_spaces(get_diff(frame, args));
	ft_printf("%d ", args->data.links);
}