/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:54:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/14 11:46:08 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//display usage on error????

static void			identify_bad_options(t_frame *frame, long bad_options)
{
	long			one;
	unsigned char	shifts;

	one = 1;
	shifts = 0;
	ft_putstr_fd("Bad Characters: ", 2);
	while (shifts < 63)
	{
		if (bad_options & one)
		{
			shifts += 97;
			write(2, &shifts, 1);
			shifts -= 97;
		}
		shifts++;
		bad_options >>= 1;
	}
	write(2, "\n", 1);
	if (frame)
		;
}

static long			get_compliment_of_all_options(t_frame *frame)
{
	char			**all_options;
	long			compliment_of_all_options;

	if(!(all_options = (char **)malloc(sizeof(char *) * 3)))
		error_exit(frame, "Malloc Failed [all_options]");
	all_options[0] = NULL;
	all_options[2] = NULL;
	if(!(all_options[1] = ft_strdup(OPTIONS)))
	{
		free(all_options);
		error_exit(frame, "Malloc Failed [all_options]");
	}
	compliment_of_all_options = ~options(all_options);
	free(all_options[1]);
	free(all_options);
	return (compliment_of_all_options);
}

static void			options_error_check(t_frame *frame, long option_data)
{
	char			**argv;
	long			compliment_of_all_options;

	argv = frame->argv;
	compliment_of_all_options = get_compliment_of_all_options(frame);
	if (option_data &= compliment_of_all_options)
	{
		identify_bad_options(frame, option_data &= compliment_of_all_options);
		error_exit(frame, "Invalid Options");
	}
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
