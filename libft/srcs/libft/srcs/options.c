/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:31:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/14 23:24:16 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//not normed
#include "libft.h"

/*
** Sets bits for alphanumeric characters.
** Sets left-most-bit in case of non-alphanumeric character
*/

static void			treat_options(char c, unsigned long *options)
{
	unsigned long	one;

	one = 1;
	if (c >= 'a' && c <= 'z')
		*options |= (one << (c - 97));
	else if (c >= 'A' && c <= 'Z')
		*options |= (one << (c - 39));
	else if (c >= '0' && c <= '9')
		*options |= (one << (c + 4));
	else
		*options |= (one << 63);
}

unsigned long		options(char **argv)
{
	unsigned long	options;
	char			*str;
	int				not_dash;

	options = 0;
	not_dash = 0;
	argv++;
	while (*argv)
	{
		str = *argv;
		if (*str == '-')
		{
			str++;
			while (*str)
			{
				treat_options(*str, &options);
				str++;
			}
		}
		else if (*str != '-' && *str != '\0')
			not_dash = 1;
		argv++;
	}
	return (options);
}
