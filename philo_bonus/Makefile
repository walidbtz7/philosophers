SRCS    		=  checker.c helper.c  init.c philo.c routine.c superviseur.c simulation.c

FLAGS 			=	-Wall -Wextra -Werror -pthread

OBJS			=    $(SRCS:.c=.o)


NAME    		=    philo_bonus

.PHONY:		all clean fclean re bonus

all: $(NAME)


$(NAME):  $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME) 

%.o:%.c 
	cc $(FLAGS) -c $< -o $@

clean:
	@rm -f ${OBJS}

fclean:    clean
	@rm -f ${NAME}
re: fclean all
