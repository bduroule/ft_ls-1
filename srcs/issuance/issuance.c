/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issuance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:55:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/22 17:34:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			distribution(t_frame *frame)
{
	loop_no_file(frame);
	loop_files(frame);
	loop_dirs(frame);
}

void				issuance(t_frame *frame)
{
	frame->current_args = frame->args;
	get_attributes(frame);
	sort(frame);
	frame->args = frame->current_args;
	distribution(frame);
}
