/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:36:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/24 17:24:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		free_individual_arg(t_frame *frame, t_args *args)
{
	if (args->data.str != frame->malloc_failed)
		free(args->data.str);
	if (args->data.path != frame->malloc_failed)
		free(args->data.path);
	if (args->data.user != frame->malloc_failed)
		free(args->data.user);
	if (args->data.group != frame->malloc_failed)
		free(args->data.group);
}

void			free_args(t_frame *frame, t_args **head)
{
	t_args		*args;
	t_args		*tmp;

	args = *head;
	while (args)
	{
		tmp = args;
		free_individual_arg(frame, args);
		args = args->next;
		free(tmp);
	}
	*head = NULL;
}
