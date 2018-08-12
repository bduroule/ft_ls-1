/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:24:15 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/12 19:33:07 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args				*create_args(void)
{
	t_args			*args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))//DONE
		return (NULL);
	ft_bzero(args, sizeof(*args));
	return (args);
}
