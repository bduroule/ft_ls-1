/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:28:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/14 01:24:12 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_ls(t_frame *frame)
{
	get_options(frame);
}

int					main(int argc, char **argv)
{
	t_frame			frame;

	ft_bzero(&frame, sizeof(frame));
	frame.argc = argc;
	frame.argv = argv;
	ft_ls(&frame);
	free_frame(&frame);
	return (0);
}
