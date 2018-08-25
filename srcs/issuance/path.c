/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:18:49 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/25 10:58:06 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				path(t_frame *frame, t_args *args, char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	if (!(args->data.str = ft_strdup(name))) //DONE
		args->data.str = frame->malloc_failed;
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1))) //DONE
		args->data.path = frame->malloc_failed;
	else
	{
		tmp = new_path;
		if (ft_strcmp(path, "."))
		{
			while (path && *path)
				*(tmp++) = *(path++);
			*(tmp++) = '/';
		}
		while (name && *name)
			*(tmp++) = *(name++);
		args->data.path = new_path;
	}
}
