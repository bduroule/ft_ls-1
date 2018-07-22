/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:12:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 17:16:34 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				no_file(t_frame *frame, t_args *args)
{
	t_data *data;

	data = &args->data;
	while (args && frame)
	{
		data = &args->data;
		if (data->no_file)
			ft_printf("ft_ls: %s: No such file or directory\n", data->str);
		args = args->next;
	}
}
