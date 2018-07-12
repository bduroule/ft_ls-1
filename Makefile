# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 15:32:02 by dhojt             #+#    #+#              #
#    Updated: 2018/06/29 19:05:04 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			lem-in
LIBFT_A =		libft.a
FT_PRINTF_A =	ft_printf.a

COMP =			gcc -Wall -Werror -Wextra -I includes -I $(LIBFT)/includes -c -o

OBJ_DIR =		obj/
S_SRC_DIR =		srcs/solution/
P_SRC_DIR =		srcs/parse/
D_SRC_DIR =		srcs/display/
L_SRC_DIR =		srcs/lem_in/

LIBFT =			libft/

S_SRC =			calc_paths.c \
				get_shortest_path.c \
				move_ants.c \
				place_ants_at_start.c \
				room_visited.c \
				set_new_start_end.c \
				simulate_start_end_move_ants.c \
				solution_debug.c \
				solution_handler.c \
				unvisit_room.c \
				visit_room.c

P_SRC =			error_ants.c \
				error_links.c \
				error_order.c \
				error_rooms.c \
				options_handler.c \
				parse_ants.c \
				parse_handler.c \
				parse_links.c \
				parse_read.c \
				parse_rooms.c \
				restructure_links.c \
				restructure_rooms.c

D_SRC =			display_debug.c \
				display_handler.c \
				display_links.c \
				display_parse.c \
				display_rooms.c \
				display_route.c \
				display_usage.c

L_SRC =			free_ants.c \
				free_links.c \
				free_parse.c \
				free_rooms.c \
				lem_in.c \
				lem_in_debug.c \
				lem_in_error.c \
				lem_in_free.c

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
				$(MAKE) logo

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

fclean:			clean
				@/bin/rm -f $(NAME) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo Cleaned $(NAME)

re: 			fclean all

logo:
	@echo "\x1b[?25l"
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[32m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[33m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[35m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[32m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[33m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[35m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[32m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[33m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[35m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[32m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[33m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[35m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "       ______                      _____        "
	@echo "       ___  /___________ ___       ___(_)______"
	@echo "       __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "       _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "       /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[32m"
	@echo " "
	@echo " "
	@echo " "
	@echo " "
	@echo "      ______                      _____        "
	@echo "      ___  /___________ ___       ___(_)______"
	@echo "      __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "      _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "      /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[33m"
	@echo " "
	@echo " "
	@echo " "
	@echo "     ______                      _____        "
	@echo "     ___  /___________ ___       ___(_)______"
	@echo "     __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "     _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "     /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[35m"
	@echo " "
	@echo " "
	@echo "    ______                      _____        "
	@echo "    ___  /___________ ___       ___(_)______"
	@echo "    __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "    _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "    /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[31m"
	@echo " "
	@echo "   ______                      _____        "
	@echo "   ___  /___________ ___       ___(_)______"
	@echo "   __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "   _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "   /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[32m"
	@echo "  ______                      _____        "
	@echo "  ___  /___________ ___       ___(_)______"
	@echo "  __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo "  _  / /  __/  / / / / //_____/  / _  / / /"
	@echo "  /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.05
	@clear
	@echo "\x1b[33m ______                      _____        "
	@echo " ___  /___________ ___       ___(_)______"
	@echo " __  /_  _ \_  __  __ \________  /__  __ \\"
	@echo " _  / /  __/  / / / / //_____/  / _  / / /"
	@echo " /_/  \___//_/ /_/ /_/       /_/  /_/ /_/ "
	@sleep 0.1
	@clear
	@echo "\x1b[35m ______                      _____"
	@echo " ___  /___________ ___       ___(_)"
	@echo " __  /_  _ \_  __  __ \________  /"
	@echo " _  / /  __/  / / / / //_____/  /"
	@echo " /_/  \___//_/ /_/ /_/       /_/"
	@sleep 0.1
	@clear
	@echo "\x1b[31m ______                     "
	@echo " ___  /___________ ___       "
	@echo " __  /_  _ \_  __  __ \________"
	@echo " _  / /  __/  / / / / //_____/"
	@echo " /_/  \___//_/ /_/ /_/       "
	@sleep 0.1
	@clear
	@echo "\x1b[32m ______                "
	@echo " ___  /___________ ___ "
	@echo " __  /_  _ \_  __  __ \\"
	@echo " _  / /  __/  / / / / /"
	@echo " /_/  \___//_/ /_/ /_/ "
	@sleep 0.1
	@clear
	@echo "\x1b[33m ______                "
	@echo " ___  /____"
	@echo " __  /_  _ \\"
	@echo " _  / /  __/"
	@echo " /_/  \___/"
	@sleep 0.1
	@clear
	@echo "\x1b[35m ______"
	@echo " ___  /"
	@echo " __  /"
	@echo " _  /"
	@echo " /_/"
	@sleep 0.1
	@clear
	@echo "\x1b[?12;25h"

.PHONY:			all clean flcean re colour logo
