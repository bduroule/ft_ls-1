/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:58:55 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/11 20:19:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_diff(t_frame *frame, char *str, long long num, int flag)
{
	int				len;

	if (str)
	{
		if (flag == LEN_USER)
			return (frame->len_user - ft_strlen(str));
		if (flag == LEN_GROUP)
			return (frame->len_group - ft_strlen(str));
		if (flag == LEN_NAME)
			return (frame->len_file_name - ft_strlen(str));
	}
	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (flag == LEN_INO)
		return (frame->len_ino - len);
	if (flag == LEN_LINKS)
		return (frame->len_links - len);
	if (flag == LEN_SIZE)
		return (frame->len_size - len);
	return (0);
}
