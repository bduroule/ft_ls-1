/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:31:05 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/13 19:35:07 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//not normed
#include "libft.h"

static void			treat_options(char c, unsigned long *options)
{
	long			one;

	one = 1;
	if (c >= 'a' && c <= 'z')
		*options |= (one << (c - 97));
	if (c >= 'A' && c <= 'Z')
		*options |= (one << (c - 39));
	if (c >= '0' && c <= '9')
		*options |= (one << (c + 4));
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
		if (*str == '-' && ft_str_is_alphanumeric(str + 1))
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
