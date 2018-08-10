/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:46:47 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 13:46:55 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_group(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.group);
	if (len > frame->len_group)
		frame->len_group = len;
}
