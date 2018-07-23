/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:42:45 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/23 16:15:33 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*get_str(int value)
{
	if (value == 1)
		return (PER_1);
	if (value == 2)
		return (PER_2);
	if (value == 3)
		return (PER_3);
	if (value == 4)
		return (PER_4);
	if (value == 5)
		return (PER_5);
	if (value == 6)
		return (PER_6);
	if (value == 7)
		return (PER_7);
	return (PER_0);
}

void				type(t_frame *frame, t_args *args)
{
	int				i;
	int				type;
	char			*str;
	char			*tmp;

	i = 3;
	type = args->data.type;
	if (!(str = (char *)malloc(sizeof(char) * 12)))
		error_exit(frame, "Malloc Failed, [permission]"); //Handle
	tmp = str;
	*(tmp++) = '-';//Make dynamic
	while (i--)
	{
		ft_strcpy(tmp, get_str((type >> (3 * i)) & 7));
		tmp += 3;
	}
	*tmp = '\0';
	ft_printf("%-12s", str);
	free(str);
}
