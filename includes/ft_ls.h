/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:26:16 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/14 00:41:15 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

typedef struct		s_options
{
	unsigned short	l		: 1;
	unsigned short	R		: 1;
	unsigned short	a		: 1;
	unsigned short	r		: 1;
	unsigned short	t		: 1;
	unsigned short	u		: 1;
	unsigned short	f		: 1;
	unsigned short	g		: 1;
	unsigned short	d		: 1;
	unsigned short	G		: 1;
	unsigned short	fill	: 6;
}					t_options;

typedef struct		s_frame
{
	int				argc;
	char			**argv;

	t_options		option;
}					t_frame;

void				free_frame(t_frame *frame);
void				error_exit(t_frame *frame, char *error_str);

#endif
