/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column_widths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 23:43:22 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 00:32:30 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			calc_len_ino(t_frame *frame, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->data.ino;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > frame->len_ino)
		frame->len_ino = len;
}

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

static void			calc_len_group(t_frame *frame, t_args *args)
{
	int				len;

	len = ft_strlen(args->data.group);
	if (len > frame->len_group)
		frame->len_group = len;
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

	frame->len_ino = 0;
	frame->len_links = 0;
	frame->len_user = 0;
	frame->len_group = 0;
	frame->len_size = 0;
	head = args;
	while (head)
	{
		if (frame->option.i)
			calc_len_ino(frame, head);
		calc_len_links(frame, head);
		calc_len_user(frame, head);
		calc_len_group(frame, head);
		calc_len_size(frame, head);
		head = head->next;
	}
}
