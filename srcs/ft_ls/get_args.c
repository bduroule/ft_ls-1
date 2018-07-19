/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:43:19 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/19 16:01:59 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			parse_options(t_frame *frame)
{
	char			**argv;
	char			**argv_options;
	int				i;

	i = 0;
	argv = frame->argv + 1;
	while (*argv && **argv == '-' && ++i)
		argv++;
	if (!i)
		return ;
	if (!(frame->argv_options = (char **)malloc(sizeof(char *) * (i + 2))))
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

void				get_args(t_frame *frame)
{
	parse_options(frame);
}
