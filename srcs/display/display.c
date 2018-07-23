/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:35:50 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/23 16:36:28 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				display(t_frame *frame, t_args *args)
{
	t_data			*data;

	data = &args->data;
	ino(frame, args);
	type(frame, args);
	ft_printf("%6d %s  %s %8d  %.24s %s \n", data->links, data->user, data->group, data->size, ctime(&data->t_time), data->str);
}
