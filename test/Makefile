# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 18:20:38 by galves-d          #+#    #+#              #
#    Updated: 2020/03/13 17:49:43 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUF_SIZE	=	9

CC		=	gcc
C_FLAGS	=	-Wall	\
			-Wextra	\
			-Werror

GNL_DIR	=	..
GNL		=	$(GNL_DIR)/get_next_line.c				\
			$(GNL_DIR)/get_next_line_utils.c
GNL_BNS	=	$(GNL_DIR)/get_next_line_bonus.c		\
			$(GNL_DIR)/get_next_line_utils_bonus.c

OBJ_DIR	=	./obj
OBJ		=	$(patsubst $(GNL_DIR)/%.c, $(OBJ_DIR)/%.o, $(GNL))
OBJ_BNS	=	$(patsubst $(GNL_DIR)/%.c, $(OBJ_DIR)/%.o, $(GNL_BNS))

all: t

$(OBJ_DIR)/%.o:	$(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -D BUFFER_SIZE=$(BUF_SIZE) -c $< -o $@

$(OBJ_DIR)/main.o:	main.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -I.. -c $< -o $@

$(OBJ_DIR)/main_bonus.o:	main_bonus.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -I.. -c $< -o $@

t: $(OBJ) $(OBJ_DIR)/main.o
	@echo "BUFFER_SIZE = $(BUF_SIZE)"
	@echo "-------------------------"
	@$(CC) $(C_FLAGS) -I.. $(OBJ) $(OBJ_DIR)/main.o -o output
	@./output
	@$(RM) -r $(OBJ_DIR)
	@$(RM) ./output

b: $(OBJ_BNS) $(OBJ_DIR)/main_bonus.o
	@echo "BUFFER_SIZE = $(BUF_SIZE)"
	@echo "-------------------------"
	@$(CC) $(C_FLAGS) -I.. $(OBJ_BNS) $(OBJ_DIR)/main_bonus.o -o output
	@./output
	@$(RM) -r $(OBJ_DIR)
	@$(RM) ./output

v: $(OBJ) $(OBJ_DIR)/main.o
	@echo "BUFFER_SIZE = $(BUF_SIZE)"
	@echo "-------------------------"
	@$(CC) $(C_FLAGS) -I.. $(OBJ) $(OBJ_DIR)/main.o -o output
	@valgrind --leak-check=full ./output
	@$(RM) -r $(OBJ_DIR)
	@$(RM) ./output

d: dev.c
	@$(CC) dev.c -o output
	@./output
	@$(RM) ./output
