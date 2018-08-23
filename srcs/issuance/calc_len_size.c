/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:47:14 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/23 07:29:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_size(t_frame *frame, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->data.size;
	if (args->data.chr)
		len = CHRSIZELEN;
	else
		while (num >= 10)
		{
			num /= 10;
			len++;
		}
	if (len > frame->len_size)
		frame->len_size = len;
}
