# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 15:32:02 by dhojt             #+#    #+#              #
#    Updated: 2018/05/14 03:40:49 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF =			ft_printf.a
LIBFT =				libft.a

COMP =				gcc -Wall -Werror -Wextra $(INCLUDES) -c -o

OBJ_DIR =			obj/
SRC_DIR =			srcs/
INCLUDES =			-I includes/

LIBFT_DIR =			$(SRC_DIR)libft/
FT_PRINTF_DIR =		$(SRC_DIR)ft_printf/

LIBFT_PATH = 		$(addprefix $(LIBFT_DIR), $(LIBFT))
FT_PRINTF_PATH =	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF))

all:
					@make -C $(LIBFT_DIR)
					@make -C $(FT_PRINTF_DIR)
					@cp $(LIBFT_PATH) .
					@cp $(FT_PRINTF_PATH) .
colour:
					@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:				colour
					@make -C $(LIBFT_DIR) fclean
					@make -C $(FT_PRINTF_DIR) fclean
					@echo Cleaned libftprintf object files

fclean:				clean
					@/bin/rm -f $(FT_PRINTF) $(LIBFT)
					@make -C $(LIBFT_DIR) fclean
					@make -C $(FT_PRINTF_DIR) fclean

re: 				fclean all

.PHONY:				all clean flcean re colour
