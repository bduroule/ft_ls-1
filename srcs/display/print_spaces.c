/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:09:41 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/06 01:10:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_spaces(int diff)
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
