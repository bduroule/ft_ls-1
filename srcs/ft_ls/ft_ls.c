/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:28:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/21 18:28:58 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_ls(t_frame *frame)
{
	parse(frame);
	issuance(frame);

	/*        TEST PRINT         */
	t_args *args = frame->current_args;
	t_data *data;
	while (args)
	{
		data = &args->data;
		if (data->no_file)
			ft_printf("ft_ls: %s: No such file or directory\n", data->str);
		args = args->next;
	}
	args = frame->current_args;
	while (args)
	{
		data = &args->data;
		if (!data->no_file)
		ft_printf("%d  %-7o %s  %s %8d  %d  %-15.15s \n", data->ino, data->type, data->user, data->group, data->size, data->t_time, data->str);
		args = args->next;
	}
	/*     END TEST PRINT        */



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
