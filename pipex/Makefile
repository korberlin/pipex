NAME = 		pipex
LIBFT = libft/
INCLUDE = -L ./libft -lft
CC = 		cc
OBJS =		$(SRCS:.c=.o)
CFLAGS = 	-Werror -Wextra -Wall -g
RM = 		rm -rf
SRCS = 		src/pipex.c\
			src/pipex_u.c\

AR	= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -g $(OBJS) $(INCLUDE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@cd $(LIBFT) && $(MAKE) clean
fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean
re:	fclean all
.PHONY: all clean fclean re
