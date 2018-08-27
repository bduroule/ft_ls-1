/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:16:42 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/27 19:12:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_end_char(t_frame *frame, t_args *args)
{
	if (frame->option.F)
	{
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
	else if (frame->option.p && args->data.dir)
		ft_putchar('/');
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
	t_data			*data;
	int				len;

	data = &args->data;
	len = data->len_of_str;
	if (frame->option.G)
		print_colour(args);
	else
		ft_printf("%s", data->str);
	print_end_char(frame, args);
	if (frame->option.l && data->lnk)
		ft_printf(" -> %s", data->sym_path);
	if (frame->number_of_columns && !frame->option.l)
		print_spaces(get_diff(frame, data->str, len, LEN_NAME) + 1);
}
