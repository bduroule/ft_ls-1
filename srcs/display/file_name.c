/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:16:42 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/18 16:18:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_F_flag(t_frame *frame, t_args *args)
{
	if (!frame->option.F)
		return ;
	if (args->data.ifo)
		ft_putchar('|');
	else if (args->data.dir)
		ft_putchar('/');
	else if (args->data.lnk)
		ft_putchar('@');
	else if (args->data.sock)
		ft_putchar('=');
	else if (args->data.wht)
		ft_putchar('%');
	else if (is_executeable(args))
		ft_putchar('*');
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
	ft_printf("%s", args->data.str);
	ft_putstr(COL_CLR);
}

void				file_name(t_frame *frame, t_args *args)
{
	if (frame->option.G)
		print_colour(args);
	else
		ft_printf("%s", args->data.str);
	print_F_flag(frame, args);
	if (frame->option.l && args->data.lnk)
		ft_printf(" -> %s", args->data.sym_path);
	if (frame->number_of_columns && !frame->option.l)
		print_spaces(get_diff(frame, args->data.str, 0, LEN_NAME) + 1);
}
