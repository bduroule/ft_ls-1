/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:14:34 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:16:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				size(t_frame *frame, t_args *args)
{
	print_spaces(get_diff(frame, NULL, args->data.size, LEN_SIZE));
	ft_printf("%d ", args->data.size);
}
