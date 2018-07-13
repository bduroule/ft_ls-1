# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 15:32:02 by dhojt             #+#    #+#              #
#    Updated: 2018/07/13 22:50:49 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_ls
LIBFT_A =		libft.a
FT_PRINTF_A =	ft_printf.a

COMP =			gcc -Wall -Werror -Wextra -I includes -I $(LIBFT)/includes -c -o

OBJ_DIR =		obj/
S_SRC_DIR =		srcs/solution/#amend
P_SRC_DIR =		srcs/parse/#amend
D_SRC_DIR =		srcs/display/#amend
L_SRC_DIR =		srcs/ft_ls/

LIBFT =			libft/

S_SRC =			#files here

P_SRC =			#files here

D_SRC =			#files here

L_SRC =			ft_ls.c \
				free_frame.c

S_OBJ =			$(S_SRC:%.c=%.o)
P_OBJ =			$(P_SRC:%.c=%.o)
D_OBJ =			$(D_SRC:%.c=%.o)
L_OBJ =			$(L_SRC:%.c=%.o)
OBJ =			$(S_OBJ) $(P_OBJ) $(D_OBJ) $(L_OBJ)

S_SRC_PATH =   	$(S_SRC:%=$(S_SRC_DIR)%)
P_SRC_PATH =   	$(P_SRC:%=$(P_SRC_DIR)%)
D_SRC_PATH =   	$(D_SRC:%=$(D_SRC_DIR)%)
L_SRC_PATH =   	$(L_SRC:%=$(L_SRC_DIR)%)
SRC_PATH =		$(S_SRC_PATH) $(P_SRC_PATH) $(D_SRC_PATH) $(L_SRC_PATH)

S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
D_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(D_OBJ))
L_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(L_OBJ))
OBJ_PATH =		$(S_OBJ_PATH) $(P_OBJ_PATH) $(D_OBJ_PATH) $(L_OBJ_PATH)

all:			colour do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n$(NAME) COMPLETE"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(S_OBJ_PATH) $(P_OBJ_PATH) \
				$(D_OBJ_PATH) $(L_OBJ_PATH) \
				$(LIBFT_A) $(FT_PRINTF_A) \
				-o $(NAME) -I includes -I $(LIBFT)/includes

$(S_OBJ_PATH):	$(S_SRC_PATH)
				@$(MAKE) $(S_OBJ)

$(P_OBJ_PATH):	$(P_SRC_PATH)
				@$(MAKE) $(P_OBJ)

$(D_OBJ_PATH):	$(D_SRC_PATH)
				@$(MAKE) $(D_OBJ)

$(L_OBJ_PATH):	$(L_SRC_PATH)
				@$(MAKE) $(L_OBJ)

$(S_OBJ):		$(LIBFT_A) $(FT_PRINTF_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)
$(P_OBJ):		$(LIBFT_A) $(FT_PRINTF_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(P_SRC_DIR)$(@:%.o=%.c)
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

.PHONY:			all clean flcean re colour
