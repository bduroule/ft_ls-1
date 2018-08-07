/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:16:42 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/07 13:23:18 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static bool			is_executeable(t_args *args)
{
	int				type;

	type = args->data.type;
	if ((type & 1) == 1 || (type >> 3 & 1) == 1 || (type >> 6 & 1) == 1)
		return (true);
	return (false);
}

static void			print_colour(t_args *args)
{
	if (is_executeable(args))
		ft_putstr(COL_EXE);
	if (args->data.ifo)	
		ft_putstr(COL_IFO);
	if (args->data.chr)
		ft_putstr(COL_CHR);
	if (args->data.dir)
		ft_putstr(COL_DIR);
	if (args->data.blk)
		ft_putstr(COL_BLK);
	if (args->data.reg && !is_executeable(args))
		ft_putstr(COL_REG);
	if (args->data.lnk)
		ft_putstr(COL_LNK);
	if (args->data.sock)
		ft_putstr(COL_SOCK);
	ft_printf("%s\n", args->data.str);
	ft_putstr(COL_CLR);
}

void				file_name(t_frame *frame, t_args *args)
{
	if (frame->option.G || COLOUR)
		print_colour(args);
	else
		ft_printf("%s\n", args->data.str);
	if (frame)
		;
}
