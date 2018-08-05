/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:35:50 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 01:03:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				display(t_frame *frame, t_args *args)
{
	t_data			*data;

	data = &args->data;
	ino(frame, args);//Do len
	type(frame, args);
	links(frame, args);
	ft_printf("%s  %s %8d ", data->user, data->group, data->size);
	show_time(frame, args);
	ft_printf("%s\n", data->str);
}
