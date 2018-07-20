/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:26:16 by dhojt             #+#    #+#             */
/*   Updated: 2018/07/20 16:11:02 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPTIONS	"-AFGRSacdfgloprtu1"

# include			"libft.h"
# include			<dirent.h>

typedef struct		s_options
{
	unsigned short	a		: 1; //show hidden
	unsigned short	c		: 1; //SORT (-t) by modification time
	unsigned short	d		: 1; //directories shown as plain files
	unsigned short	f		: 1; //SORT by nothing, turns on -a
	unsigned short	g		: 1; //owner name surpressed
	unsigned short	l		: 1; //list in long format
	unsigned short	o		: 1; //group name surpressed
	unsigned short	r		: 1; //reverse
	unsigned short	t		: 1; //SORT by modified time
	unsigned short	u		: 1; //SORT (-t) by access time
	unsigned short	A		: 1; //shows hidden files except '.' and '..'
	unsigned short	F		: 1; //prints some character after filename
	unsigned short	G		: 1; //colours
	unsigned short	R		: 1; //Recursivly list subdirectories
	unsigned short	S		: 1; //SORT by size
	unsigned short	one		: 1; //Forces one column output (turns off -a)
}					t_options;

typedef struct		s_args
{
	char			*str;

	int				type;
	char			*user;
	char			*group;
	int				size;

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

	unsigned char	headers	: 1;//
	unsigned char	fill	: 7;//

	t_options		option;

	t_args			*args;
	t_args			*current_args;
}					t_frame;

void				parse(t_frame *frame);
void				get_args(t_frame *frame);
void				get_options(t_frame *frame);
void				config_options(t_frame *frame);

void				issuance(t_frame *frame);
void				get_attributes(t_frame *frame);
void				do_ls(t_frame *frame);

void				sort(t_frame *frame);

void				error_exit(t_frame *frame, char *error_str);
void				free_frame(t_frame *frame);

#endif
