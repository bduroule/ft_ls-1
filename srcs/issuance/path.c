/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:18:49 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/12 17:19:00 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				path(t_frame *frame, t_args *args, char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	if (!(args->data.str = ft_strdup(name)))
		error_exit(frame, "Malloc Failed [new_name]");// Handle carefully (recurse)
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		error_exit(frame, "Malloc Failed [new_path]");// Handle carefully (recurse)
	tmp = new_path;
	while (path && *path)
		*(tmp++) = *(path++);
	*(tmp++) = '/';
	while (name && *name)
		*(tmp++) = *(name++);
	args->data.path = new_path;
}
