# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauvez <nfauvez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 12:24:35 by nfauvez           #+#    #+#              #
#    Updated: 2023/09/13 10:36:14 by nfauvez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################### COMPILATION #################################

NAME		=	philo

CC			=	cc

FLAG		=	-Wall -Werror -Wextra

################################ Colors #####################################

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
BLUE = \033[1;34m
WHITE = \033[1;37m

############################### PROJECT FILES ###############################

SRC				=	alive.c \
					check_alive.c \
					check_alive_utils.c \
					eating.c \
					init.c \
					main.c \
					philo.c \
					return_error.c \
					utils.c

HEADER			=	philo.h

OBJ				=	$(SRC:.c=.o)

################################## RULES ####################################

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)\nCOMPILING PHILO...\n"
	$(CC) $(FLAG) $^ -o $@
	@echo "$(GREEN)Philo created! ᕦ($(RED)♥$(GREEN)_$(RED)♥$(GREEN))ᕤ$(WHITE)"

############################### NORM RULES ##################################

norm:
	@echo "$(YELLOW)Norminette...$(WHITE)"
	@norminette $(SRC) $(HEADER)
	@echo "$(GREEN)Norminette done$(WHITE)"

############################### CLEAN RULES #################################

clean:
	@echo "$(RED)Deleting Philo object...\n"
	@rm -f $(OBJ)
	@echo "$(GREEN)Done\n"

fclean: clean
	@echo "$(RED)Deleting Philo executable..."
	@rm -f $(NAME)
	@echo "$(RED)Philo deleted! ⌐(ಠ۾ಠ)¬$(WHITE)"


re: fclean all
	@echo "$(BLUE)Philo recompiled!$(WHITE)"

############################### OTHER RULES #################################

party:
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 1
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean norm re party
