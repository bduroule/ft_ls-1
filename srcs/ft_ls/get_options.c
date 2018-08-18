/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:54:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/18 16:55:19 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_bad_options(t_frame *frame, unsigned long bad_options)
{
	char			option_char;
	unsigned long	one;
	unsigned char	shifts;
	char			correction;

	one = 1;
	shifts = 0;
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	while (shifts < 63)
	{
		correction = (shifts < 26) ? 97 : 39;
		(shifts > 51) ? correction = -4 : 0;
		(shifts > 62) ? correction = -30 : 0;
		if (bad_options & one)
		{
			option_char = shifts + correction;
			write(2, &option_char, 1);
		}
		shifts++;
		bad_options >>= 1;
	}
	ft_putstr_fd("\nusage: ./ft_ls [", 2);
	ft_putstr_fd(OPTIONS, 2);
	error_exit(frame, "] [file ...]");
}

static void			get_compliment_of_all_options(t_frame *frame,
		unsigned long *compliment_of_all_options)
{
	char			**all_options;

	if (!(all_options = (char **)malloc(sizeof(char *) * 3)))
		error_exit(frame, "Malloc Failed [all_options]");
	all_options[0] = NULL;
	all_options[2] = NULL;
	if (!(all_options[1] = ft_strdup(OPTIONS)))
	{
		free(all_options);
		error_exit(frame, "Malloc Failed [all_options]");
	}
	*compliment_of_all_options = ~options(all_options);
	free(all_options[1]);
	free(all_options);
}

static void			options_error_check(t_frame *frame,
		unsigned long option_data)
{
	char			**argv;
	unsigned long	compliment_of_all_options;

	argv = frame->argv;
	get_compliment_of_all_options(frame, &compliment_of_all_options);
	if (option_data &= compliment_of_all_options)
		print_bad_options(frame, option_data &= compliment_of_all_options);
}

void				get_options(t_frame *frame)
{
	unsigned long	one;
	unsigned long	option_data;

	if (!frame->argv_options)
		return ;
	one = 1;
	option_data = options(frame->argv_options);
	frame->option.a = (option_data & (one << ('a' - 97))) ? 1 : 0;
	frame->option.c = (option_data & (one << ('c' - 97))) ? 1 : 0;
	frame->option.d = (option_data & (one << ('d' - 97))) ? 1 : 0;
	frame->option.f = (option_data & (one << ('f' - 97))) ? 1 : 0;
	frame->option.g = (option_data & (one << ('g' - 97))) ? 1 : 0;
	frame->option.i = (option_data & (one << ('i' - 97))) ? 1 : 0;
	frame->option.l = (option_data & (one << ('l' - 97))) ? 1 : 0;
	frame->option.o = (option_data & (one << ('o' - 97))) ? 1 : 0;
	frame->option.p = (option_data & (one << ('p' - 97))) ? 1 : 0;
	frame->option.r = (option_data & (one << ('r' - 97))) ? 1 : 0;
	frame->option.t = (option_data & (one << ('t' - 97))) ? 1 : 0;
	frame->option.u = (option_data & (one << ('u' - 97))) ? 1 : 0;
	frame->option.x = (option_data & (one << ('x' - 97))) ? 1 : 0;
	frame->option.A = (option_data & (one << ('A' - 39))) ? 1 : 0;
	frame->option.F = (option_data & (one << ('F' - 39))) ? 1 : 0;
	frame->option.G = (option_data & (one << ('G' - 39))) ? 1 : 0;
	frame->option.N = (option_data & (one << ('N' - 39))) ? 1 : 0;
	frame->option.R = (option_data & (one << ('R' - 39))) ? 1 : 0;
	frame->option.S = (option_data & (one << ('S' - 39))) ? 1 : 0;
	frame->option.T = (option_data & (one << ('T' - 39))) ? 1 : 0;
	frame->option.U = (option_data & (one << ('U' - 39))) ? 1 : 0;
	frame->option.one = (option_data & (one << ('1' + 4))) ? 1 : 0;
	options_error_check(frame, option_data);
}
