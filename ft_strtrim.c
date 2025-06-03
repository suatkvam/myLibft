#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	int end;
	char * trimmed;
	end = ft_strlen(s1);
	i = 0;
	if(!s1)
		return (NULL);
	if(!set)
		return ft_strdup("");

	while (s1[i] && ft_strchr(set,s1[i]))
		i = i + 1;
	while(end > i && ft_strchr(set,s1[end - 1]))
		end = end - 1;
	trimmed = (char*) malloc(end - i + 1);
	if(!trimmed)
		return (NULL);
	ft_memcpy(trimmed,s1 + i,end - i);
	trimmed[end - i] = '\0';
	return (trimmed);
}

int main(int argc, char const *argv[])
{
	char* s1 = "1   abc   merhaba   ";
	printf("%s",ft_strtrim(s1," "));
	return 0;
}
