NAME        =    philo

IDIR        =    philo.h

SRCS		=	philo.c \
				check_arg.c \
				ft_libft.c \
				init.c \
				lst_libft.c \
				simu.c \
				utils.c \
				eat_fork.c \
				sleep_think.c \
				end_sim.c \

OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -pthread #-fsanitize=thread
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

n			:
	$(NORM)

clean		:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY:		all clean fclean re bonus