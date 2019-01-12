NAME		= 	ft_retro

SRCS		= 	Agent.cpp\
				Enemy.cpp\
				Mesh.cpp \
				Player.cpp\
				Projectile.cpp\
				Weapon.cpp\
				World.cpp\
				main.cpp

OBJS		= 	$(patsubst srcs/%.cpp,objs/%.o,$(SRCS))

CC			= 	clang++
CFLAGS		= 	-Wall -Wextra -Werror


all:		$(NAME)

$(NAME):	$(OBJS)
			@ $(CC) $(CFLAGS) -o $@ $^
			@ echo "\n\033[92m---> project program created ✓\033[0m"

clean:
			@ /bin/rm -rf objs/
			@ echo "\033[1;33m---> All .o files cleared\033[0m \033[92m✓\033[0m"

fclean:		clean
			@ /bin/rm -f $(NAME)
			@ echo "\n\033[1;33m---> Everything cleared\033[2;00m \033[92m✓\033[0m"
re : fclean all

.PHONY: clean, fclean, re