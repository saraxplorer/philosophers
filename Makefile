# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rshaheen <rshaheen@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/04 11:49:40 by rshaheen      #+#    #+#                  #
#    Updated: 2024/12/04 13:50:03 by rshaheen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread #-flto -Ofast

RM = rm -f

SOURCE =	main.c \
			print_msg.c \
			input_check.c \
			

OBJECTS = $(SOURCE:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

all: $(NAME)
	
$(NAME): $(OBJS_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re