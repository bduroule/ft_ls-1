/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:38:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 14:06:29 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				show_time(t_frame *frame, t_args *args)
{
	char			*time;

	time = ctime(&args->data.t_time);
	//ft_printf("%.24s ", ctime(&args->data.t_time));
	ft_printf("%2.2s ", time + 8);
	ft_printf("%3.3s ", time + 4);
	ft_printf("%5.5s ", time + 11);
	if (frame && args)
		;
}
