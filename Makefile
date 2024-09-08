NAME = libftprintf.a


SRCDIR		= src
BUILDDIR	= build
INCLUDE 	= include

MAND_SRCS = mandatory/ft_printf.c
BONUS_SRCS = bonus/ft_printf_bonus.c

MAND_OBJECTS = $(MAND_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Add build dir before all object files
MAND_OBJECTS := $(addprefix $(BUILDDIR)/, $(MAND_OBJECTS))
BONUS_OBJS := $(addprefix $(BUILDDIR)/, $(BONUS_OBJS))

# Add soucre dir before all source files
MAND_SRCS := $(addprefix $(SRCDIR)/, $(MAND_SRCS))
BONUS_SRCS := $(addprefix $(SRCDIR)/, $(BONUS_SRCS))


all: $(NAME)

bonus: $(NAME) $(BONUS_OBJS)
	@ar d $(NAME) $(MAND_OBJECTS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@echo add bonus objects to $(NAME)

LIBFTDIR	= libft
include libft/include.mk

INCLUDE := $(addprefix -I, $(INCLUDE))


libft: $(LIBFT)
	@$(MAKE) -C $(LIBFTDIR) all


$(NAME): $(OBJECTS) $(MAND_OBJECTS)
	@ar rcs $@ $^
	@echo add all objects to $(NAME)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo Build $@ object from $<
	@$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

clean:
#	@$(MAKE) -C $(LIBFTDIR) clean
	@rm -f $(OBJECTS) $(MAND_OBJECTS) $(BONUS_OBJS)
	@echo FT_PRINTF remove all object files

fclean: clean
#	@$(MAKE) -C $(LIBFTDIR) fclean
	@rm -f $(NAME)
	@echo FT_PRINTF remove all files

re: fclean all


a.out: $(NAME) main.c
	@cc $(INCLUDE) -L. main.c $(NAME) -o a.out

test: a.out
	@./a.out

.PHONY: all clean fclean re