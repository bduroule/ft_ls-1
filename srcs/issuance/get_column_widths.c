/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column_widths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 23:43:22 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 00:20:43 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			calc_len_links(t_frame *frame, t_args *args)
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
	if (len > frame->len_links)
		frame->len_links = len;
}

static void			calc_len_user(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.user);
	if (len > frame->len_user)
		frame->len_user = len;
}

static void			calc_len_size(t_frame *frame, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->data.size;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > frame->len_size)
		frame->len_size = len;
}

void				get_column_widths(t_frame *frame, t_args *args)
{
	t_args			*head;

	frame->len_links = 0;
	frame->len_user = 0;
	frame->len_groups = 0;
	frame->len_size = 0;
	head = args;
	while (head)
	{
		calc_len_links(frame, head);
		calc_len_user(frame, head);
		calc_len_size(frame, head);
		head = head->next;
	}
	ft_printf("%d | %d | %d | %d\n\n", frame->len_links, frame->len_user, frame->len_groups, frame->len_size);
}
