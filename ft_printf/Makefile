SRCS		=	ft_printf.c ft_printfutils.c\

OBJS		=	${SRCS:.c=.o}

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

NAME = 		ft_printf.a

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY :	all fclean re
