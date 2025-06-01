NAME= libft.a

# SRC=  \.c

# BONUS_SRC=

OBJECT_FILE= $(SRC:.c=.o)
#src dosyanlarını .o çeviriyor 
# BONUS_OBJECT_FİLE=$(BONUS:.c=.o) # bonus c dosyalarını objeye çeviriyor

CC= cc -Wall -Wextra -Werror


%.o: %.c
	${CC} $< -o $@

$(NAME): $(OBJECT_FILE)
	 	ar -rc $(NAME) $(OBJECT_FILE)
	@echo denemme
# bonus: $(BONUS_OBJECT_FILE)
# 	ar -r $(NAME) $^

clean:
	rm -f $(OBJECT_FILE) $(BONUS_OBJECT_FILE)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus
