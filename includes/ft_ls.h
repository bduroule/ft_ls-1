/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:26:16 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/12 19:33:37 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define COLOUR		1
# define COLUMN		1

# define LEN_INO	1
# define LEN_LINKS	2
# define LEN_USER	3
# define LEN_GROUP	4
# define LEN_SIZE	5
# define LEN_NAME	6

# define OPTIONS	"-AFGNRSTUacdfgiloprtux1"
# define NUM_FILES	"--------------\nFiles: %d\n"
# define SIX_MONTHS	15768000

# define TYPE_IFO	010000
# define TYPE_CHR	020000
# define TYPE_DIR	040000
# define TYPE_BLK	060000
# define TYPE_REG	0100000
# define TYPE_LNK	0120000
# define TYPE_SOCK	0140000
# define TYPE_WHT	0160000

# define COL_IFO	"\x1b[31m"
# define COL_CHR	"\x1b[31m"
# define COL_DIR	"\x1b[1m\x1b[36m"
# define COL_BLK	"\x1b[31m"
# define COL_REG	"\x1b[0m"
# define COL_LNK	"\x1b[31m"
# define COL_SOCK	"\x1b[31m"
# define COL_WHT	"\x1b[31m"
# define COL_EXE	"\x1b[31m"
# define COL_CLR	"\x1b[0m"

# define PER_LEN	11
# define PER_BLK	'b'
# define PER_CHR	'c'
# define PER_DIR	'd'
# define PER_LNK	'l'
# define PER_SOCK	's'
# define PER_IFO	'p'
# define PER_REG	'-'
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
	unsigned char	x		: 1; //Horizontal list
	unsigned char	A		: 1; //shows hidden files except '.' and '..'
	unsigned char	F		: 1; //prints some character after filename
	unsigned char	G		: 1; //colours
	unsigned char	N		: 1; //Number of files displayed.
	unsigned char	R		: 1; //Recursivly list subdirectories
	unsigned char	S		: 1; //SORT by size
	unsigned char	T		: 1; //Shows time in full format
	unsigned char	U		: 1; //SORT by (-t) by birth time
	unsigned char	one		: 1; //Forces one column output (turns off -a)
	unsigned char	fill 	: 3;
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

	unsigned char	ifo		: 1;
	unsigned char	chr		: 1;
	unsigned char	dir		: 1;
	unsigned char	blk		: 1;
	unsigned char	reg		: 1;
	unsigned char	lnk		: 1;
	unsigned char	sock	: 1;
	unsigned char	wht		: 1;
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

	time_t			time_now;
	time_t			time_6_months_ago;

	int				len_ino;
	int				len_links;
	int				len_user;
	int				len_group;
	int				len_size;
	int				len_file_name;
	int				items_to_display;

	int				width;
	int				number_of_columns;

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
void				free_args(t_args **args);
t_args				*create_args(void);

void				issuance(t_frame *frame);
void				get_attributes(t_frame *frame);
void				loop_no_file(t_frame *frame);
void				loop_files(t_frame *frame);
void				loop_dirs(t_frame *frame);
void				loop_valid_dir(t_frame *frame, t_args *args);
void				do_ls(t_frame *frame, t_args *args);
void				calc_len_ino(t_frame *frame, t_args *args);
void				calc_len_links(t_frame *frame, t_args *args);
void				calc_len_user(t_frame *frame, t_args *args);
void				calc_len_group(t_frame *frame, t_args *args);
void				calc_len_size(t_frame *frame, t_args *args);
void				calc_len_file_name(t_frame *frame, t_args *args);
void				calculate_number_of_columns(t_frame *frame);
void				path(t_frame *frame, t_args *args, char *path, char *name);

void				sort(t_frame *frame);
void				assign_sort(t_frame *frame);
bool				sort_alpha(t_frame *frame);
bool				sort_alpha_r(t_frame *frame);
bool				sort_size(t_frame *frame);
bool				sort_size_r(t_frame *frame);
bool				sort_time(t_frame *frame);
bool				sort_time_r(t_frame *frame);

void				display(t_frame *frame, t_args *args);
void				no_file(t_frame *frame, t_args *args);
void				ino(t_frame *frame, t_args *args);
void				links(t_frame *frame, t_args *args);
void				type(t_frame *frame, t_args *args);
void				user_and_group(t_frame *frame, t_args *args);
void				size(t_frame *frame, t_args *args);
void				show_time(t_frame *frame, t_args *args);
void				file_name(t_frame *frame, t_args *args);
void				print_spaces(int diff);
int					get_diff(t_frame *frame, char *str, long long num, int flag);

void				error_exit(t_frame *frame, char *error_str);
void				free_frame(t_frame *frame);

#endif
