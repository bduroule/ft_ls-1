/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:38:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 13:56:50 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				show_time(t_frame *frame, t_args *args)
{

	ft_printf("%.24s ", ctime(&args->data.t_time));
	if (frame && args)
		;
}
