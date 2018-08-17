/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:36:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/17 16:04:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		free_individual_arg(t_args *args)
{
	free(args->data.str);
	free(args->data.path);
	free(args->data.user);
	free(args->data.group);
}

void			free_args(t_args **head)
{
	t_args		*args;
	t_args		*tmp;

	args = *head;
	while (args)
	{
		tmp = args;
		free_individual_arg(args);
		args = args->next;
		free(tmp);
	}
	*head = NULL;
}
