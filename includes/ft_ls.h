/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:26:16 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/05 14:53:34 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPTIONS	"-AFGRSUacdfgiloprtu1"

# define PER_LEN	11
# define PER_BLOC	"b"
# define PER_CHAR	"c"
# define PER_DIR	"d"
# define PER_SYM	"l"
# define PER_SOCK	"s"
# define PER_FIFO	"p"
# define PER_REG	"-"
# define PER_N		"-"
# define PER_R		"r"
# define PER_W		"w"
# define PER_X		"x"// CHECK - COULD BE S or s.
# define PER_0		PER_N PER_N PER_N
# define PER_1		PER_N PER_N PER_X
# define PER_2		PER_N PER_W PER_N
# define PER_3		PER_N PER_W PER_X
# define PER_4		PER_R PER_N PER_N
# define PER_5		PER_R PER_N PER_X
# define PER_6		PER_R PER_W PER_N
# define PER_7		PER_R PER_W PER_X

# include			"libft.h"
# include			<dirent.h>
# include			<stdbool.h>
# include			<time.h>

typedef struct		s_options
{
	unsigned char	a		: 1; //show hidden
	unsigned char	c		: 1; //SORT (-t) by status change time
	unsigned char	d		: 1; //directories shown as plain files
	unsigned char	f		: 1; //SORT by nothing, turns on -a
	unsigned char	g		: 1; //owner name surpressed
	unsigned char	i		: 1; //print inode
	unsigned char	l		: 1; //list in long format
	unsigned char	o		: 1; //group name surpressed
	unsigned char	r		: 1; //reverse
	unsigned char	t		: 1; //SORT by modified time
	unsigned char	u		: 1; //SORT (-t) by access time
	unsigned char	A		: 1; //shows hidden files except '.' and '..'
	unsigned char	F		: 1; //prints some character after filename
	unsigned char	G		: 1; //colours
	unsigned char	R		: 1; //Recursivly list subdirectories
	unsigned char	S		: 1; //SORT by size
	unsigned char	U		: 1; //SORT by (-t) by birth time
	unsigned char	one		: 1; //Forces one column output (turns off -a)
	unsigned char	fill 	: 6;
}					t_options;

typedef struct		s_data
{
	char			*str;
	char			*path;

	unsigned char	no_file	: 1;
	unsigned char	fill	: 7;

	long long		ino;
	int				type;
	int				links;
	char			*user;
	char			*group;
	int				size;
	time_t			c_time;
	time_t			t_time;
	time_t			u_time;
	time_t			U_time;
}					t_data;

typedef struct		s_args
{
	t_data			data;
	struct s_args	*next;
}					t_args;

typedef struct		s_frame
{
	int				argc;
	char			**argv;

	char			**argv_options;

	unsigned char	headers	: 1;//
	unsigned char	fill	: 7;//

	char			no_args[2];

	time_t			time_now;
	time_t			time_6_months_ago;

	t_options		option;

	t_args			*args;
	t_args			*current_args;
	t_args			*head;
	t_args			*track;

	bool			(*sort_function)(struct s_frame *frame);
}					t_frame;

void				parse(t_frame *frame);
void				get_args(t_frame *frame);
void				get_options(t_frame *frame);
void				config_options(t_frame *frame);
t_args				*create_args(t_frame *frame);

void				issuance(t_frame *frame);
void				get_attributes(t_frame *frame);
void				loop_no_file(t_frame *frame);
void				loop_files(t_frame *frame);
void				loop_dirs(t_frame *frame);
void				loop_valid_dir(t_frame *frame, t_args *args);
bool				is_file(t_args *args);
void				do_ls(t_frame *frame, t_args *args);

void				sort(t_frame *frame);
bool				sort_alpha(t_frame *frame);
bool				sort_alpha_r(t_frame *frame);

void				display(t_frame *frame, t_args *args);
void				no_file(t_frame *frame, t_args *args);
void				ino(t_frame *frame, t_args *args);
void                type(t_frame *frame, t_args *args);
void                show_time(t_frame *frame, t_args *args);

void				error_exit(t_frame *frame, char *error_str);
void				free_frame(t_frame *frame);

#endif
