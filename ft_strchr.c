#include"libft.h"


char	*ft_strchr(const char *s, int c)
{
	char *str = (char *)s;
	size_t i;
	i = 0;

	while(str[i])
	{
		if(str[i] == c)
		return(str + i);
		i++;
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	char *a = "merhaba dünya";
	char b = 'd';
	printf("%s",ft_strchr(a,b));
	return 0;
}
