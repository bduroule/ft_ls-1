/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:47:37 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 13:47:47 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_file_name(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.str);
	if (len > frame->len_file_name)
		frame->len_file_name = len;
}
