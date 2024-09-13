# Set final target name
NAME	= libftprintf.a

# Set colors variables
RESET	= \033[0;39m
RED		= \033[0;91m
GREEN	= \033[0;92m
MAGENTA	= \033[0;95m
YELLOW	= \033[0;93m

# Set Dirs path
SRCDIR		= src
BUILDDIR	= build
INCLUDE 	= include

# Set source files to SOURCES variable
SOURCES = \
		ft_printf.c				\
		ft_printf_redirect.c	\
		ft_flags_parser.c		\
		ft_handlers.c			\
		ft_handlers2.c			\
		ft_decimal_handler.c	\
		ft_flags_apply.c

# Convert ext source file from .c to .o
OBJECTS = $(SOURCES:.c=.o)

# Add build dir prefix all object files
OBJECTS := $(addprefix $(BUILDDIR)/, $(OBJECTS))

# Add soucre dir prefix all source files
SOURCES := $(addprefix $(SRCDIR)/, $(SOURCES))

# Rule all for make libftprintf.a and libft.a
all: $(NAME)

# Rule bonus redirect to NAME
bonus: $(NAME)

# Set path for libft dir before include
# Include libft/include.mk
# for add all libft objects and sources to (OBJECTS, SOURCES) variables
# and load rule for make object files from source file .c -> .o
LIBFTDIR	= libft
include libft/include.mk

# Add prefix -I to all include dirs for use in compiler 
INCLUDE := $(addprefix -I, $(INCLUDE))

# Rule for make libftprintf.a, prerequisites is all objects in libftprintf and libft projects
$(NAME): $(OBJECTS)
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory
	@test -f $(NAME) \
	&& echo "$(MAGENTA)Update archive $(NAME) $(RESET)" \
	|| echo "$(MAGENTA)Create archive $(NAME) $(RESET)"
	@ar rcs $@ $?
	

# Rule libft for make libft.a and our objects only
libft:
	$(MAKE) -C $(LIBFTDIR) all	

# Rule for build source files
# and dir if not exists
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@ \
	&& echo "$(GREEN)Build $@ object from $< $(RESET)"\
	|| echo "$(RED)Error in try build $< $(RESET)"

# Clean all object file in libftprintf and libft
clean:
	@rm -f $(OBJECTS) $(MAND_OBJECTS) $(BONUS_OBJS) \
	&& echo "$(YELLOW)LIBFTPRINTF: remove all object files$(RESET)"\
	|| echo "$(RED)LIBFTPRINTF: Can't remove object files$(RESET)"
	

# Clean all objects and libftpritf.a, libft.a
fclean: clean
	@rm -f $(LIBFT) \
	&& echo "$(YELLOW)LIBFTPRINTF: Remove all $(LIBFT)$(RESET)"\
	|| echo "$(RED)LIBFTPRINTF: Can't remove $(LIBFT)$(RESET)"
	@rm -f $(NAME) \
	&& echo "$(YELLOW)LIBFTPRINTF: Remove $(NAME)$(RESET)"\
	|| echo "$(RED)LIBFTPRINTF: Can't remove $(NAME)$(RESET)"

# Clean all object files and archives files and build again
re: fclean all

.PHONY: all clean fclean re bonus libft
