/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len_ino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:44:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 13:45:02 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_ino(t_frame *frame, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->data.ino;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > frame->len_ino)
		frame->len_ino = len;
}
