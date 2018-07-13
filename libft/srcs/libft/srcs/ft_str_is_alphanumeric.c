/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alphanumeric.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:46:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/13 16:53:39 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Not normed
#include "libft.h"

int		ft_str_is_alphanumeric(char *str)
{
	int fail;

	fail = 0;
	while (*str)
	{
		if (!ft_isalpha(*str) && !ft_isdigit(*str))
			fail = 1;
		str++;
	}
	return ((fail) ? 0 : 1);
}
