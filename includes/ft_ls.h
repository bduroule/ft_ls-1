/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:26:16 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/19 21:51:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPTIONS	"-GRadfglrtu"

# include			"libft.h"
# include			<dirent.h>

typedef struct		s_options
{
	unsigned short	a		: 1;
	unsigned short	d		: 1;
	unsigned short	f		: 1;
	unsigned short	g		: 1;
	unsigned short	l		: 1;
	unsigned short	r		: 1;
	unsigned short	t		: 1;
	unsigned short	u		: 1;
	unsigned short	G		: 1;
	unsigned short	R		: 1;
	unsigned short	fill	: 6;
}					t_options;

typedef struct		s_args
{
	char			*str;
	unsigned char	file	: 1;
	unsigned char	dir		: 1;
	unsigned char	fill	: 6;

	struct s_args	*next;
}					t_args;

typedef struct		s_frame
{
	int				argc;
	char			**argv;

	char			**argv_options;

	unsigned char	headers	: 1;
	unsigned char	fill	: 7;

	t_options		option;
	t_args			*args;
}					t_frame;

void				parse(t_frame *frame);
void				get_args(t_frame *frame);
void				get_options(t_frame *frame);
void				config_options(t_frame *frame);

void				error_exit(t_frame *frame, char *error_str);
void				free_frame(t_frame *frame);

#endif
