/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:20:45 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/23 14:35:52 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_path(t_frame *frame, t_args *args, bool do_print)
{
	static intmax_t	print_path_count = 0;

	if (do_print)
	{
		if (frame->headers && print_path_count)
			ft_printf("\n%s:\n", args->data.path);
		else if (frame->headers)
			ft_printf("%s:\n", args->data.path);
	}
	print_path_count++;
}
