NAME= libft.a

SRC=	ft_atoi.c     ft_bzero.c     ft_calloc.c    ft_calloc.o    ft_isalnum.c \
		ft_isalpha.c  ft_isascii.c   ft_isascii.o   ft_isdigit.c   ft_isprint.c \
		ft_itoa.c     ft_memchr.c    ft_memchr.o    ft_memcmp.c    ft_memcmp.o \
		ft_memcpy.c   ft_memcpy.o    ft_memmove.c   ft_memset.c    ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c   ft_strchr.c \
		ft_strchr.o   ft_strdup.c    ft_striteri.c  ft_strjoin.c   ft_strlcat.c \
		ft_strlcat.o  ft_strlcpy.c   ft_strlcpy.o   ft_strlen.c    ft_strmapi.c \
		ft_strncmp.c  ft_strncmp.o   ft_strnstr.c   ft_strrchr.c   ft_strrchr.o \
		ft_strtrim.c  ft_substr.c    ft_tolower.c   ft_toupper.c


# BONUS_SRC=


# BONUS_SRC=

OBJECT_FILE= $(SRC:.c=.o)
#src dosyanlarını .o çeviriyor 
# BONUS_OBJECT_FİLE=$(BONUS:.c=.o) # bonus c dosyalarını objeye çeviriyor

CC= cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJECT_FILE)
	ar -rcs $(NAME) $(OBJECT_FILE)
	@echo "derleme tamamlandi"

clean:
	rm -f $(OBJECT_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus
