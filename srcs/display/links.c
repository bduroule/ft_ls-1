/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:44:12 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 01:04:38 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_diff(t_frame *frame, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->data.links;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (frame->len_links - len);
}

static void			print_spaces(int diff)
{
	char			*spaces;

	if (diff < 1)
		return;
	if ((spaces = (char *)malloc(sizeof(char) * (diff + 1))))
	{
		ft_memset(spaces, ' ', diff);
		spaces[diff] = '\0';
		ft_putstr(spaces);
		free(spaces);
	}
}

void				links(t_frame *frame, t_args *args)
{
	print_spaces(get_diff(frame, args));
	ft_printf("%d ", args->data.links);
}
