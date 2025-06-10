#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	char *temp;
	int str_len;

	i = 0;
	if(!s || !f)
		return (NULL);
	
	str_len = ft_strlen(s);
	temp = (char *)malloc(str_len + 1);

	if(!temp)
		return (NULL);
	while (i < str_len)
	{
		temp[i] = f(i,s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}