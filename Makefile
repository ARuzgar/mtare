NAMESERVER = server
NAMECLIENT = client
NAMESERVERBONUS = server_bonus
NAMECLIENTBONUS = client_bonus
LIB = ./ft_printf/ft_printf.a
SRCSERVER = server.c
SRCCLIENT = client.c
SRCSERVERBONUS = server_bonus.c
SRCCLIENTBONUS = client_bonus.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
OBJSERVERBONUS = $(SRCSERVERBONUS:.c=.o)
OBJCLIENTBONUS = $(SRCCLIENTBONUS:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)


$(LIB):
	make -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)


bonus: $(LIB) $(NAMESERVERBONUS) $(NAMECLIENTBONUS)

$(NAMESERVERBONUS) : $(OBJSERVERBONUS)
	$(CC) $(OBJSERVERBONUS) -o $(NAMESERVERBONUS) $(LIB)

$(NAMECLIENTBONUS) : $(OBJCLIENTBONUS)
	$(CC) $(OBJCLIENTBONUS) -o $(NAMECLIENTBONUS) $(LIB)


clean:
	@rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJSERVERBONUS) $(OBJCLIENTBONUS)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT) $(NAMESERVERBONUS) $(NAMECLIENTBONUS)

ffclean: fclean
	make fclean -C ./ft_printf

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@

norm:
	norminette *.[ch]

re: fclean all

.PHONY : re fclean clean all ffclean norm
