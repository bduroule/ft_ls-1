/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:43:19 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:58:56 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			get_path(t_frame *frame, t_args *args,
		char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	args->data.str = name;
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		error_exit(frame, "Malloc Failed [new_path]");
	tmp = new_path;
	while (path && *path)
		*(tmp++) = *(path++);
	*(tmp++) = '/';
	while (name && *name)
		*(tmp++) = *(name++);
	args->data.path = new_path;
}

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
	while (*argv && **argv == '-' && argv[0][1])
	{
		*argv_options = *argv;
		argv++;
		argv_options++;
	}
	*argv_options = NULL;
}

static void			parse_args(t_frame *frame, int option)
{
	char			**argv;
	t_args			*args;
	t_args			*last_args;

	argv = frame->argv + option;
	if (*argv)
		argv++;
	if (!*argv)
	{
		frame->args = create_args(frame);
		frame->no_args[0] = '.';
		frame->args->data.str = frame->no_args;
		if (!(frame->args->data.path = ft_strdup(".")))
			error_exit(frame, "Malloc Failed [. path]");
	}
	while (*argv)
	{
		args = create_args(frame);
		get_path(frame, args, ".", *argv);
		if (!(args->data.path = ft_strdup(*argv)))
			error_exit(frame, "Malloc Failed [path]");
		if (!frame->args)
			frame->args = args;
		else
			last_args->next = args;
		last_args = args;
		argv++;
	}
}

static int			calculate_option_strings(t_frame *frame)
{
	char			**argv;
	int				option;

	option = 0;
	argv = frame->argv + 1;
	while (*argv && **argv == '-' && argv[0][1])
	{
		option++;
		if (!ft_strcmp(*argv, "--"))
			break ;
		argv++;
	}
	return (option);
}

void				get_args(t_frame *frame)
{
	parse_options(frame, calculate_option_strings(frame));
	parse_args(frame, calculate_option_strings(frame));
}
