/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:43:19 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/19 16:16:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			parse_options(t_frame *frame, int option)
{
	char			**argv;
	char			**argv_options;

	if (!option)
		return ;
	if (!(frame->argv_options = (char **)malloc(sizeof(char *) * (option + 2))))
		error_exit(frame, "Malloc Failed [frame->argv_options]");
	*frame->argv_options = *frame->argv;	
	argv = frame->argv + 1;
	argv_options = frame->argv_options + 1;
	while (*argv && **argv == '-')
	{
		*argv_options = *argv;
		argv++;
		argv_options++;
	}
	*argv_options = NULL;
}

static int			calculate_option_strings(t_frame *frame)
{
	char			**argv;
	int				option;

	option = 0;
	argv = frame->argv + 1;
	while (*argv && **argv == '-')
	{
		option++;
		argv++;
	}
	return (option);
}

void				get_args(t_frame *frame)
{
	parse_options(frame, calculate_option_strings(frame));
}
