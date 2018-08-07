/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:35:50 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/07 12:18:09 by dhojt            ###   ########.fr       */
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
	user_and_group(frame, args);
	size(frame, args);
	show_time(frame, args);
	file_name(frame, args);
}
