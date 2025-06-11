NAME= libft.a

SRC=   ft_isascii.c ft_memcpy.c  ft_strjoin.c ft_strrchr.c \
		ft_atoi.c  ft_isdigit.c ft_memmove.c ft_strlcat.c ft_strtrim.c \
		ft_bzero.c ft_isprint.c ft_memset.c  ft_strlcpy.c ft_substr.c \
		ft_calloc.c  ft_itoa.c  ft_split.c ft_strlen.c  ft_tolower.c \
		ft_isalnum.c ft_memchr.c  ft_strchr.c  ft_strncmp.c ft_toupper.c \
		ft_isalpha.c ft_memcmp.c  ft_strdup.c  ft_strnstr.c

# BONUS_SRC=


# BONUS_SRC=

OBJECT_FILE= $(SRC:.c=.o)
#src dosyanlarını .o çeviriyor 
# BONUS_OBJECT_FİLE=$(BONUS:.c=.o) # bonus c dosyalarını objeye çeviriyor

CC= cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECT_FILE)
	ar -rcs $(NAME) $(OBJECT_FILE)
	@echo "derleme tamamlandi"

clean:
	rm -f $(OBJECT_FILE) $(BONUS_OBJECT_FILE)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus
