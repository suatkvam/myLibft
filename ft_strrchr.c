#include"libft.h"
#include<stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *str = (char *)s;
	size_t i;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[--i])
	{
		if (str[i] == c)
		{
			return (str + i);
		}
	}
	return 0;
}

int main()
{
	char *a = "merhakba kdünyak";
	char s = 'k';
	printf("%s \n",ft_strrchr(a,s));
	return 0;
}
