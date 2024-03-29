# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/13 20:12:00 by fmaury            #+#    #+#              #
#    Updated: 2019/01/13 20:12:03 by fmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++


NAME 			= ft_retro

HEADER_PATH 	= includes
SRC_PATH 		= srcs

SRC_NAME		= Agent.cpp\
				  Alien.cpp\
				  BigAlien.cpp\
				  Enemy.cpp\
				  Player.cpp\
				  Projectile.cpp\
				  Spaceship.cpp\
				  Weapon.cpp\
				  World.cpp\
				  main.cpp

OBJ_PATH =  obj
OBJ_NAME =  $(SRC_NAME:.cpp=.o)
CPPFLAGS = -I$(HEADER_PATH) 
LIBFLAG = -lncurses
CFLAGS = -Wall -Wextra -Werror 

SRCS := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CPPFLAGS)  $(LIBFLAG) -o $@
	@printf $(GREEN)"$(NAME) Finish linking\n"$(EOC)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf $(GREEN)"compiling %s\n"$(GREEN) $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null

clean:
	@rm -f $(OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf $(GREEN)"$(NAME) clean\n"$(EOC)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf $(GREEN)"$(NAME) fclean\n"$(EOC)

re: fclean all

norme:
	@norminette $(SRCS)
	@norminette $(HEADER_PATH)/*.h

.PHONY: clean fclean all re norme
