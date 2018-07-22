/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:28:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 17:41:09 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_ls(t_frame *frame)
{
	parse(frame);
	issuance(frame);
	free_frame(frame);
}

int					main(int argc, char **argv)
{
	t_frame			frame;

	ft_bzero(&frame, sizeof(frame));
	frame.argc = argc;
	frame.argv = argv;
	ft_ls(&frame);
	return (0);
}
