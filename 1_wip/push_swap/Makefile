# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/10/15 10:47:54 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

NAME		=	push_swap
GCC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror
DIRSRC		=	./src/
DIRINC		=	./include/
MAKEFLAGS	+=	--no-print-directory

# source and object files
SRC_MAIN	=	push_swap.c
SRC_LOG		= 	${SRC_MAIN}									\
				logger/logger.c
SRC_MAPPER	=	${SRC_LOG}									\
				mapper/mapper_rank.c						
SRC_OPTI	=	${SRC_MAPPER}								\
				optimizer/optimizer.c						\
				optimizer/optimizer_utils.c
SRC_UTILS	=	${SRC_OPTI}									\
				utils/error.c								\
				utils/init_data.c							\
				utils/malloc.c
SRC_VALID	=	$(SRC_UTILS)								\
				validation/validate_args.c					\
				validation/validate_int_str.c				\
				validation/validate_duplicate.c
SRC_STACK	=	$(SRC_VALID)								\
				stack/fill_stack.c							\
				stack/init_stack.c							\
				stack/utils_stack.c							\
				stack/nav_stack.c							\
				stack/ops_push.c							\
				stack/ops_reverse_rotate.c					\
				stack/ops_rotate.c							\
				stack/ops_basic.c							\
				stack/ops_swap.c							
SRC_SORT	=	$(SRC_STACK)								\
				sorter/chunk_sort_three.c					\
				sorter/chunk_sort.c							\
				sorter/chunk_split_utils.c					\
				sorter/chunk_split.c						\
				sorter/chunk_utils.c						\
				sorter/easy_sort.c							\
				sorter/edgecase.c							\
				sorter/move.c								\
				sorter/sort.c
SRCS		=	$(addprefix	$(DIRSRC),	$(SRC_SORT))
OBJS		=	$(SRCS:.c=.o)

# lib
LIBFT_DIR	=	./lib/libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_LINK	=	-L$(LIBFT_DIR) -lft
CFLAGS		+=	-I$(LIBFT_DIR)/include

# colors
GREEN		=	\033[032m
CYAN		=	\033[036m
NOCLR		=	\033[0m

# RULES
# **************************************************************************** #

all:			$(LIBFT) $(NAME)

$(NAME):		$(OBJS)
					@$(GCC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LINK)
					@printf "$(GREEN)%-12s%-12s\n$(NOCLR)" "compiled" "$(NAME)"
$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)

.c.o:
		@$(GCC) $(CFLAGS) -I$(DIRINC) -c $< -o $(<:.c=.o)

bonus:	all

clean:
		@$(RM) $(OBJS)
		@$(MAKE) -C $(LIBFT_DIR) clean
		@printf "$(CYAN)%-12s%-12sOBJECTS\n$(NOCLR)" "cleaned" "$(NAME)"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) -C $(LIBFT_DIR) QUIET=1 fclean
			@printf "$(CYAN)%-12s%-12sPROGRAMS\n$(NOCLR)" "cleaned" "$(NAME)"

re:		fclean all

test:	fclean
			@echo "Compiling with test CFLAGS"
			@$(MAKE) CFLAGS="-g -I$(LIBFT_DIR)/include" all 
			@$(MAKE) clean

.PHONY:		all bonus clean fclean re

# **************************************************************************** #
