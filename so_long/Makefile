NAME	=	so_long

SRCS	=	srcs/so_long.c	srcs/keys.c	srcs/move_left_right.c	srcs/move_up_down.c\
		srcs/parser_check.c	srcs/parser_errors.c	srcs/parser_init.c\

SRCS_B	=	src_bonus/so_long_b.c	src_bonus/keys_b.c	src_bonus/move_left_right_b.c	src_bonus/move_up_down_b.c\
		src_bonus/parser_check_b.c	src_bonus/parser_errors_b.c	src_bonus/parser_init_b.c\


HEADER	=	so_long.h

OBJS	=	$(SRCS:%.c=%.o)

OBJS_B	=	$(SRCS_B:%.c=%.o)

CC		=	gcc

LIBFT	=	-L libft -lft

INC		=	-I includes -I libft -I mlx

CFLAGS	=	 -Wall -Wextra -Werror -I -Imlx

MLX		=	-L minilibx -lmlx -framework Opengl	-framework AppKit

.PHONE	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLX) $(OBJS) -o $(NAME)

bonus	:	$(OBJS_B) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLX) $(OBJS_B) -o $(NAME)

%.o		:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS) $(OBJS_B)
	@echo "Cleaned"

fclean	: clean
	@$(RM) $(NAME)
	@echo "fcleaned"

re		:	fclean all
