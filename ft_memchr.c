#include"libft.h"



void	*ft_memchr(const void *s1, int c, size_t n)
{
	size_t i;
	unsigned char *str = (unsigned char*) s1;

	while (str[i])
	{
		if (str[i] == c && i < n)
			return(str + i);
		i++;
	}
	return NULL;
	
}
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *a = "merhaba dünya";
	char b = 'd';
	char* s = ft_memchr(a,b,9);
	char* f = memchr(a,b,9);
	printf("%s",s);
	printf("\n");
	printf("%s",f);
	return 0;
}