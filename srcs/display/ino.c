/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ino.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:40:13 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:11:53 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ino(t_frame *frame, t_args *args)
{
	if (!frame->option.i)
		return ;
	print_spaces(get_diff(frame, NULL, args->data.ino, LEN_INO));
	ft_printf("%lld ", args->data.ino);
}
