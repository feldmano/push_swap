# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: opelman <opelman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/04/08 12:25:41 by opelman       #+#    #+#                  #
#    Updated: 2024/09/13 14:09:30 by opelman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

FLAGS		:=	-Wall -Werror -Wextra

LINKS		:=	-L./libft -lft

SRC_DIR		:=	src

SRC			:=	$(shell find $(SRC_DIR) -name '*.c')

OBJ_DIR		:=	obj

OBJ			:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cc -o $(NAME) $(FLAGS) $(OBJ) $(LINKS) && \
	echo "\e[32mmade $(NAME)\e[0m";

obj/%.o:	src/%.c
	mkdir -p $(dir $@)
	cc -c $(FLAGS) $(HEADERS) $< -o $@

$(LIBFT):
	$(MAKE) -C libft
	$(MAKE) clean -C libft

re:
	@$(MAKE) fclean all -s
	
debug: 
	$(MAKE) fclean FLAGS="$(FLAGS) -g -fsanitize=address" all

clean:
	@if [ -d "obj" ]; then \
		rm -fr obj; \
		rm -fr ./src/libft/obj; \
		echo "\e[31mremoved object files\e[0m"; \
	else \
		echo "\e[32mno object files to clean\e[0m"; \
	fi

fclean:
	@if [ -d "obj" ]; then \
		$(MAKE) clean -s; \
	fi
	@if [ -f "push_swap" ]; then \
		rm -f $(NAME); \
		echo "\e[31mremoved push_swap\e[0m"; \
	else \
		echo "\e[32mno program file to clean\e[0m"; \
	fi

phony: all re debug clean fclean
