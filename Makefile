NAME = libftprintf.a


SRCDIR		= src
BUILDDIR	= build
INCLUDE 	= include

SOURCES = ft_printf.c ft_digit_count.c
OBJECTS = $(SOURCES:.c=.o)

# Add build dir before all object files
OBJECTS := $(addprefix $(BUILDDIR)/, $(OBJECTS))

# Add soucre dir before all source files
SOURCES := $(addprefix $(SRCDIR)/, $(SOURCES))


all: $(NAME)

#bonus: $(NAME)

LIBFTDIR	= libft
include libft/include.mk

INCLUDE := $(addprefix -I, $(INCLUDE))


libft: $(LIBFT)
	@$(MAKE) -C $(LIBFTDIR) all

$(NAME): $(OBJECTS)
	@ar rcs $@ $(OBJECTS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo Build $@ $<
	@$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@rm -f $(OBJECTS)
	@echo FT_PRINTF remove all object files

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	@rm -f $(NAME)
	@echo FT_PRINTF remove all files

re: fclean all


a.out: $(NAME) main.c
	@cc $(INCLUDE) -L. main.c $(NAME) -o a.out

test: a.out
	@./a.out

.PHONY: all clean fclean re