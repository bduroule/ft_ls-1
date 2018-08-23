/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:14:34 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/23 07:21:47 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>

void				size(t_frame *frame, t_args *args)
{
	if (args->data.chr)
	{
		print_spaces(get_diff(frame, NULL, 0, LEN_SIZE_C));
		ft_printf("%3d, %3d ", major(args->data.rdev), minor(args->data.rdev));
	}
	else
	{
		print_spaces(get_diff(frame, NULL, args->data.size, LEN_SIZE));
		ft_printf("%d ", args->data.size);
	}
}
