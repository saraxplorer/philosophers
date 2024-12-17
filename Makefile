# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rshaheen <rshaheen@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/04 11:49:40 by rshaheen      #+#    #+#                  #
#    Updated: 2024/12/17 13:46:28 by rshaheen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

RM = rm -f

SOURCE =	main.c \
			print_msg.c \
			input_check.c \
			init_data.c \
			allocate_fork_lock.c \
			allocate_philo.c \
			simulation.c \
			time_and_duration.c \
			eat.c \
			supervise.c \
			clean.c \
			
			

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