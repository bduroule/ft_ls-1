/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:12:31 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 17:45:31 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				no_file(t_frame *frame, t_args *args)
{
	if (args->data.no_file && frame)
		ft_printf("ft_ls: %s: No such file or directory\n", args->data.str);
	args = args->next;
}
