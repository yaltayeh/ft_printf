# If LIBFTDIR not define set '.',
# else Set before include,
# because include libft from anywhere
ifndef LIBFTDIR
LIBFTDIR = .
endif

# Set colors variables
RESET	= \033[0;39m
RED		= \033[0;91m
GREEN	= \033[0;92m
MAGENTA	= \033[0;95m
YELLOW	= \033[0;93m

# Set dirs path and set 
LIBFT_SRCDIR	 = $(LIBFTDIR)/src
LIBFT_BUILDDIR	 = $(LIBFTDIR)/build
INCLUDE 		+= $(LIBFTDIR)/include

# Set final target path
LIBFT = $(LIBFTDIR)/libft.a

# Set all source files to LIBFT_SOURCES
LIBFT_SOURCES =	\
			ft_string/ft_isalnum.c			\
			ft_string/ft_isascii.c			\
			ft_string/ft_isalpha.c			\
			ft_string/ft_isdigit.c			\
			ft_string/ft_isprint.c			\
			ft_string/ft_isspace.c			\
			ft_string/ft_itoa.c				\
			ft_string/ft_itoa_base.c		\
			ft_string/ft_split.c			\
			ft_string/ft_strchr.c			\
			ft_string/ft_strdup.c			\
			ft_string/ft_striteri.c			\
			ft_string/ft_strjoin.c			\
			ft_string/ft_strlcat.c			\
			ft_string/ft_strlcpy.c			\
			ft_string/ft_strlen.c	 		\
			ft_string/ft_strmapi.c			\
			ft_string/ft_strncmp.c			\
			ft_string/ft_strnstr.c			\
			ft_string/ft_strrchr.c			\
			ft_string/ft_strtrim.c			\
			ft_string/ft_substr.c			\
			ft_string/ft_tolower.c			\
			ft_string/ft_toupper.c

LIBFT_SOURCES +=	\
			ft_memory/ft_bzero.c			\
			ft_memory/ft_memset.c			\
			ft_memory/ft_memcpy.c			\
			ft_memory/ft_memmove.c			\
			ft_memory/ft_memchr.c			\
			ft_memory/ft_memcmp.c			\
			ft_memory/ft_calloc.c

LIBFT_SOURCES +=	\
			ft_io/ft_putchar.c				\
			ft_io/ft_putstr.c				\
			ft_io/ft_putnbr_with_zero.c				\
			ft_io/ft_atoi.c					\
			ft_io/ft_putchar_fd.c			\
			ft_io/ft_putstr_fd.c			\
			ft_io/ft_putendl_fd.c			\
			ft_io/ft_putnbr_fd.c			\
			ft_io/ft_putbase_fd.c
			
LIBFT_SOURCES +=	\
			ft_linked_list/ft_lstnew.c			\
			ft_linked_list/ft_lstadd_front.c	\
			ft_linked_list/ft_lstsize.c			\
			ft_linked_list/ft_lstlast.c			\
			ft_linked_list/ft_lstadd_back.c		\
			ft_linked_list/ft_lstdelone.c		\
			ft_linked_list/ft_lstclear.c		\
			ft_linked_list/ft_lstiter.c			\
			ft_linked_list/ft_lstmap.c
#

# Convert all source files from .c to .o
LIBFT_OBJECTS  += $(LIBFT_SOURCES:.c=.o)

# Add build dir before all object files
LIBFT_OBJECTS := $(addprefix $(LIBFT_BUILDDIR)/, $(LIBFT_OBJECTS))

# Add soucre dir before all source files
LIBFT_SOURCES := $(addprefix $(LIBFT_SRCDIR)/, $(LIBFT_SOURCES))

# Add all libft source file to OBJECTS
SOURCES += $(LIBFT_SOURCES)
# Add all libft object file to SOURCES
OBJECTS += $(LIBFT_OBJECTS)

# Build object(.o) file from source(.c) file
# and dir if not exists
$(LIBFT_BUILDDIR)/%.o: $(LIBFT_SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -I$(INCLUDE) $< -o $@ \
		&& echo "$(GREEN)Build $@ object from $< $(RESET)"\
		|| echo "$(RED)Error in try build $< $(RESET)"