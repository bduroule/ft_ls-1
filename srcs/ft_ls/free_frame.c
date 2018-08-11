/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 22:44:38 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 21:22:40 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_args(t_args **args)//Break out - should not be static
{
	while (*args)
	{
		free ((*args)->data.str);
		free ((*args)->data.path);
		free ((*args)->data.user);
		free ((*args)->data.group);
		*args = (*args)->next;
	}
}

void				free_frame(t_frame *frame)
{
	//free_args(&frame->args);
	//free everything LOL.
	if (frame)
		;
}
