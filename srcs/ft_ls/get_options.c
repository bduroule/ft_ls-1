/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:54:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/14 01:58:57 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//display usage on error????

static void			options_error_check(t_frame *frame, long option_data)
{
	char			**argv;
	long			compliment_of_all_options;

	argv = frame->argv;
	compliment_of_all_options = 0xFFFFF7FEFFE5F796;
	if (option_data &= compliment_of_all_options)
		error_exit(frame, "Invalid Options");
	while (*argv)
	{
		if (!ft_strcmp(*argv, "-"))
			error_exit(frame, "Invalid Options");
		argv++;
	}
}

void				get_options(t_frame *frame)
{
	long			one;
	long			option_data;

	one = 1;
	option_data = options(frame->argv);
	frame->option.a = (option_data & (one << ('a' - 97))) ? 1 : 0;
	frame->option.d = (option_data & (one << ('d' - 97))) ? 1 : 0;
	frame->option.f = (option_data & (one << ('f' - 97))) ? 1 : 0;
	frame->option.g = (option_data & (one << ('g' - 97))) ? 1 : 0;
	frame->option.l = (option_data & (one << ('l' - 97))) ? 1 : 0;
	frame->option.r = (option_data & (one << ('r' - 97))) ? 1 : 0;
	frame->option.t = (option_data & (one << ('t' - 97))) ? 1 : 0;
	frame->option.u = (option_data & (one << ('u' - 97))) ? 1 : 0;
	frame->option.G = (option_data & (one << ('G' - 39))) ? 1 : 0;
	frame->option.R = (option_data & (one << ('R' - 39))) ? 1 : 0;
	options_error_check(frame, option_data);
}
