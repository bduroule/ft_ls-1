/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:45:11 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 13:45:24 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_links(t_frame *frame, t_args *args)
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
	if (len > frame->len_links)
		frame->len_links = len;
}
