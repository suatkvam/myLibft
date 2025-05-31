#include"libft.h"
#include<bsd/string.h>
#include<stdio.h>
char *ft_strnstr(const char *big, const char *little, size_t len)
{
	char* str = (char*) big;
	char* to_find = (char*) little;
	size_t i;
	size_t j;
	i = 0;

	if(to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && j <= len)
		{
			if (to_find[j + 1] == '\0')
				return(&str[i]);
			j++;
		}
		i++;
	}	
	return 0;

}

int main(int argc, char const *argv[])
{	
	char str[] = "merhaba, dünya";
	char find[] = "h";
	printf("%s",strnstr(str,find,4));
	printf("\n");
	printf("%s",ft_strnstr(str,find,4));
	return 0;
}
