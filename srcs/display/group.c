/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:34:46 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 01:36:58 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_diff(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.group);
	return (frame->len_group - len);
}

void				group(t_frame *frame, t_args *args)
{
	ft_putstr(args->data.group);
	print_spaces(get_diff(frame, args) + 2);
}
