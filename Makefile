# NAME= libft

# # SRC= buraya C dosyaları gelecek

# # SRC_BONUS= buraya bonustaki c dosyaları gelecek

# OBJECT: %.o : %.c # dosyaları objecte çevirecek
# 	${SRC} ${}
# CC= cc -Wall -Wextra _werror # compile için değişkene

# all: # c dosyaları burada o dosyalarına bakılacak ve ar kısmı eklenecek # ar -rc libname -l kod_dosyası/dosyaları.c
# 	${CC} - c
# clean:# c dosyaları harici oluşturdu dosyaları silecek
# 	rm -rf ${all}
# # fclean: #clean ile aynı işlem

# # re: # clean yada f clean işlemini yapıp geri make yapıcak

# .PHONY: all, clean,fclean,re

NAME= libft

SRC= ft_atoi.c

# BONUS_SRC=

OBJECT_FILE= $(SRC:.c=.o)
#src dosyanlarını .o çeviriyor 
# BONUS_OBJECT_FİLE=$(BONUS:.c=.o) # bonus c dosyalarını objeye çeviriyor

CC= cc -Wall -Wextra -Werror


%.o: %.c
	${CC} $< -o $@

$(NAME): $(OBJECT_FILE)
	 	ar -rc $(NAME) $(OBJECT_FILE)

# bonus: $(BONUS_OBJECT_FILE)
# 	ar -r $(NAME) $^

clean:
	rm -f $(OBJECT_FILE) $(BONUS_OBJECT_FILE)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus
