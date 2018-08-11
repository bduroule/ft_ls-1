/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:44:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:15:40 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				links(t_frame *frame, t_args *args)
{
	print_spaces(get_diff(frame, NULL, args->data.links, LEN_LINKS));
	ft_printf("%d ", args->data.links);
}
