/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:28:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/24 16:10:35 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

static void			ft_ls(t_frame *frame)
{
	parse(frame);
	issuance(frame);
	free_frame(frame);
}

static t_frame		create_frame(int argc, char **argv)
{
	t_frame			frame;
	struct winsize	window_size;

	ft_bzero(&frame, sizeof(frame));
	frame.argc = argc;
	frame.argv = argv;
	if(!(frame.malloc_failed = ft_strdup("Malloc failed")))
		exit(1);
	time(&frame.time_now);
	frame.time_6_months_ago = frame.time_now - SIX_MONTHS;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size) == -1)
		frame.option.one = 1;
	frame.width = window_size.ws_col;
	return (frame);
}

int					main(int argc, char **argv)
{
	t_frame			frame;

	frame = create_frame(argc, argv);
	ft_ls(&frame);
	return (0);
}
