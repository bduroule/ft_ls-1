/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:16:42 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/07 12:27:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_colour(t_args *args)
{
	if (args->data.ifo)	
		ft_putstr(COL_IFO);
	if (args->data.chr)
		ft_putstr(COL_CHR);
	if (args->data.dir)
		ft_putstr(COL_DIR);
	if (args->data.blk)
		ft_putstr(COL_BLK);
	if (args->data.reg)
		ft_putstr(COL_REG);
	if (args->data.lnk)
		ft_putstr(COL_LNK);
	if (args->data.sock)
		ft_putstr(COL_SOCK);
}

void				file_name(t_frame *frame, t_args *args)
{
	if (frame->option.G)
		print_colour(args);
	ft_printf("%s\n", args->data.str);
	ft_putstr(COL_CLR);
	if (frame)
		;
}
