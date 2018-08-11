/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:38:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:28:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static time_t		get_file_time(t_frame *frame, t_args *args)
{
	if (frame->option.c)
		return (args->data.c_time);
	if (frame->option.u)
		return (args->data.u_time);
	if (frame->option.U)
		return (args->data.U_time);
	else
		return (args->data.t_time);
}

void				show_time(t_frame *frame, t_args *args)
{
	char			*string;
	time_t			time;

	time = get_file_time(frame, args);
	string = ctime(&time);
	ft_printf("%3.3s ", string + 4);
	ft_printf("%2.2s ", string + 8);
	if (frame->option.T)
		ft_printf("%.13s ", string + 11);
	else if (time < frame->time_6_months_ago || time > frame->time_now)
		ft_printf("%5.4s ", string + 20);
	else
		ft_printf("%5.5s ", string + 11);
	if (frame && args)
		;
}
