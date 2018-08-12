# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 15:32:02 by dhojt             #+#    #+#              #
#    Updated: 2018/08/12 17:19:35 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_ls
INCLUDES = 		includes
HEADER =		$(INCLUDES)/ft_ls.h
LIBFT_A =		libft.a
FT_PRINTF_A =	ft_printf.a

#  --------------------REMOVE -g  #
COMP =			gcc -Wall -Werror -Wextra -I $(INCLUDES) -I $(LIBFT)/includes -c -g -o

OBJ_DIR =		obj/
S_SRC_DIR =		srcs/sort/
I_SRC_DIR =		srcs/issuance/
D_SRC_DIR =		srcs/display/
L_SRC_DIR =		srcs/ft_ls/

LIBFT =			libft/

S_SRC =			sort.c \
				sort_alpha.c \
				sort_alpha_r.c \
				sort_size.c \
				sort_size_r.c \
				sort_time.c \
				sort_time_r.c \
				assign_sort.c

I_SRC =			issuance.c \
				get_attributes.c \
				do_ls.c \
				path.c \
				loop_no_file.c \
				loop_files.c \
				loop_dirs.c \
				loop_valid_dir.c \
				calc_len_ino.c \
				calc_len_links.c \
				calc_len_user.c \
				calc_len_group.c \
				calc_len_size.c \
				calc_len_file_name.c \
				calculate_number_of_columns.c

D_SRC =			display.c \
				no_file.c \
				ino.c \
				type.c \
				links.c \
				get_diff.c \
				user_and_group.c \
				size.c \
				show_time.c \
				file_name.c \
				print_spaces.c

L_SRC =			ft_ls.c \
				free_frame.c \
				error_exit.c \
				get_options.c \
				get_args.c \
				parse.c \
				config_options.c \
				create_args.c

S_OBJ =			$(S_SRC:%.c=%.o)
I_OBJ =			$(I_SRC:%.c=%.o)
D_OBJ =			$(D_SRC:%.c=%.o)
L_OBJ =			$(L_SRC:%.c=%.o)
OBJ =			$(S_OBJ) $(I_OBJ) $(D_OBJ) $(L_OBJ)

S_SRC_PATH =   	$(S_SRC:%=$(S_SRC_DIR)%)
I_SRC_PATH =   	$(I_SRC:%=$(I_SRC_DIR)%)
D_SRC_PATH =   	$(D_SRC:%=$(D_SRC_DIR)%)
L_SRC_PATH =   	$(L_SRC:%=$(L_SRC_DIR)%)
SRC_PATH =		$(S_SRC_PATH) $(I_SRC_PATH) $(D_SRC_PATH) $(L_SRC_PATH)

S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
I_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(I_OBJ))
D_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(D_OBJ))
L_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(L_OBJ))
OBJ_PATH =		$(S_OBJ_PATH) $(I_OBJ_PATH) $(D_OBJ_PATH) $(L_OBJ_PATH)

all:			colour do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n$(NAME) COMPLETE"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(S_OBJ_PATH) $(I_OBJ_PATH) \
				$(D_OBJ_PATH) $(L_OBJ_PATH) \
				$(LIBFT_A) $(FT_PRINTF_A) \
				-o $(NAME) -I $(INCLUDES) -I $(LIBFT)/includes

$(S_OBJ_PATH):	$(S_SRC_PATH) $(HEADER)
				@$(MAKE) $(S_OBJ)

$(I_OBJ_PATH):	$(I_SRC_PATH) $(HEADER)
				@$(MAKE) $(I_OBJ)

$(D_OBJ_PATH):	$(D_SRC_PATH) $(HEADER)
				@$(MAKE) $(D_OBJ)

$(L_OBJ_PATH):	$(L_SRC_PATH) $(HEADER)
				@$(MAKE) $(L_OBJ)

$(S_OBJ):		$(LIBFT_A) $(FT_PRINTF_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)
$(I_OBJ):		$(LIBFT_A) $(FT_PRINTF_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(I_SRC_DIR)$(@:%.o=%.c)
$(D_OBJ):		$(LIBFT_A) $(FT_PRINTF_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(D_SRC_DIR)$(@:%.o=%.c)
$(L_OBJ):		$(LIBFT_A) $(FT_PRINTF_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(L_SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .
				@cp $(LIBFT)/$(FT_PRINTF_A) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			colour
				@/bin/rm -rf $(OBJ_DIR) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo Cleaned libft object files

fclean:			colour
				@/bin/rm -rf $(OBJ_DIR) $(FT_PRINTF_A) $(LIBFT_A)
				@/bin/rm -f $(NAME) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo Cleaned $(NAME) and object files

re: 			fclean all

.PHONY:			all clean flcean re colour do_libft
