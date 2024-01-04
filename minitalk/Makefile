# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afromont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 08:55:23 by afromont          #+#    #+#              #
#    Updated: 2023/12/29 12:05:18 by afromont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECLI = client
NAMESERV = server
NAMECLIBONUS = client_bonus
NAMESERVBONUS = server_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3
RM = rm -f
SRCCLI = client.c utils.c
SRCSERV = server.c utils.c
SRCCLIBONUS = client_bonus.c utils.c
SRCSERVBONUS = server_bonus.c utils.c
OBJCLI = $(SRCCLI:.c=.o)
OBJSERV = $(SRCSERV:.c=.o)
OBJCLIBONUS = $(SRCCLIBONUS:.c=.o)
OBJSERVBONUS = $(SRCSERVBONUS:.c=.o)

all:	$(NAMECLI) $(NAMESERV) $(NAMECLIBONUS) $(NAMESERVBONUS)

$(NAMECLI) : $(OBJCLI)
	$(CC) $(OBJCLI) $(CFLAGS) -o $(NAMECLI)

$(NAMESERV) : $(OBJSERV)
	$(CC) $(OBJSERV) $(CFLAGS) -o $(NAMESERV)

$(NAMECLIBONUS) : $(OBJCLIBONUS)
	$(CC) $(OBJCLIBONUS) $(CFLAGS) -o $(NAMECLIBONUS)

$(NAMESERVBONUS) : $(OBJSERVBONUS)
	$(CC) $(OBJSERVBONUS) $(CFLAGS) -o $(NAMESERVBONUS)

clean : 
	$(RM) $(OBJCLI)
	$(RM) $(OBJSERV)
	$(RM) $(OBJCLIBONUS)
	$(RM) $(OBJSERVBONUS)

fclean : clean
	$(RM) $(NAMECLI)
	$(RM) $(NAMESERV)
	$(RM) $(NAMECLIBONUS)
	$(RM) $(NAMESERVBONUS)

re : fclean all

	
