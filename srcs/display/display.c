/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:35:50 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 17:04:58 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				display(t_frame *frame, t_args *args)
{
	t_data *data;

	data = &args->data;
	ft_printf("%d  %-7o %s  %s %8d  %d  %-15.15s \n", data->ino, data->type, data->user, data->group, data->size, data->t_time, data->str);
	if (frame)
		;
}
