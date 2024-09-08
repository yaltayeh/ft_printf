# Set Target file
NAME = libft.a

# Compiler settings
CC=cc
CFLAGS = -Wall -Wextra -Werror

# all rule
all: $(NAME)

include include.mk

# libft.a rule
$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@echo LIBFT remove all files 

clean:
	@rm -f $(OBJECTS)
	@echo LIBFT remove all object files

re: fclean all

.PHONY: all clean fclean re
