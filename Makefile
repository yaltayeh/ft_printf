NAME = libftprintf.a


SRCDIR		= src
BUILDDIR	= build
INCLUDE 	= include

SOURCES = \
		ft_printf.c									\
		ft_printf_redirect.c						\
		ft_flags_parser.c							\
		handlers/ft_put_address_handle.c  			\
		handlers/ft_put_decimal_handle.c			\
		handlers/ft_put_hexadecimal_handle.c		\
		handlers/ft_put_str_handle.c				\
		handlers/ft_put_unsigned_decimal_handle.c

OBJECTS = $(SOURCES:.c=.o)

# Add build dir before all object files
OBJECTS := $(addprefix $(BUILDDIR)/, $(OBJECTS))

# Add soucre dir before all source files
SOURCES := $(addprefix $(SRCDIR)/, $(SOURCES))

all: $(NAME)

bonus: $(NAME)

LIBFTDIR	= libft
include libft/include.mk

INCLUDE := $(addprefix -I, $(INCLUDE))

libft: $(LIBFT)
	@$(MAKE) -C $(LIBFTDIR) all


$(NAME): $(OBJECTS)
	@ar rcs $@ $^
	@echo add all objects to $(NAME)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo Build $@ object from $<
	@$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

clean:
	@rm -f $(OBJECTS) $(MAND_OBJECTS) $(BONUS_OBJS)
	@echo FT_PRINTF remove all object files

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo FT_PRINTF remove all files

re: fclean all

a.out: $(NAME) main.c
	@cc $(INCLUDE) -L. main.c $(NAME) -o a.out

test: a.out
	@./a.out

.PHONY: all clean fclean re bonus