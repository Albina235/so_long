NAME	=	libft.a

SRCS = ft_putstr_fd.c	ft_split.c	ft_strdup.c\
		ft_strlen.c	ft_strncmp.c	ft_strrchr.c	ft_strchr.c\
		get_next_line.c	get_next_line_utils.c ft_itoa.c\

HEADER	= 	libft.h

OBJ		=	$(SRCS:%.c=%.o)

CC		= 	gcc

FLAGS	=	 -Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			ar r $(NAME) $?

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			@rm -rf $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
