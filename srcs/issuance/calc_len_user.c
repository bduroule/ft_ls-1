/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len_user.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:46:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/10 13:46:36 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_user(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.user);
	if (len > frame->len_user)
		frame->len_user = len;
}
