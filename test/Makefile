# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 18:20:38 by galves-d          #+#    #+#              #
#    Updated: 2020/03/11 20:39:52 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUF_SIZE	=	5

CC		=	gcc
C_FLAGS	=	-Wall	\
			-Wextra	\
			-Werror

GNL_DIR	=	..
GNL		=	$(GNL_DIR)/get_next_line.c			\
			$(GNL_DIR)/get_next_line_utils.c

OBJ_DIR	=	./obj
OBJ		=	$(patsubst $(GNL_DIR)/%.c, $(OBJ_DIR)/%.o, $(GNL))

all: t

$(OBJ_DIR)/%.o:	$(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -D BUFFER_SIZE=$(BUF_SIZE) -c $< -o $@

$(OBJ_DIR)/main.o:	main.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -I.. -c $< -o $@

t: $(OBJ) $(OBJ_DIR)/main.o
	@echo "BUFFER_SIZE = $(BUF_SIZE)"
	@echo "-------------------------"
	@$(CC) $(C_FLAGS) -I.. $(OBJ) $(OBJ_DIR)/main.o -o output
	@./output
	@$(RM) -r $(OBJ_DIR)
	@$(RM) ./output

d: dev.c
	@$(CC) dev.c -o output
	@./output
	@$(RM) ./output
