/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:14:34 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/22 23:32:19 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>

void				size(t_frame *frame, t_args *args)
{
	print_spaces(get_diff(frame, NULL, args->data.size, LEN_SIZE));
	if (args->data.chr)
		ft_printf("%4d,%4d ", major(args->data.rdev), minor(args->data.rdev));
	else
		ft_printf("%d ", args->data.size);
}
