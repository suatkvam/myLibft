#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	char * joined;

	if(!s1 || !s2)
		return NULL;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	joined = (char *)malloc(s1_len + s2_len + 1);

	if(!joined)
		return (NULL);

	ft_strlcpy(joined,s1,s1_len + 1);
	ft_strlcat(joined,s2,s1_len + s2_len + 1);
	return joined;
}
/* int main(int argc, char const *argv[])
{
	char  *s1 = "hello, ";
	char *s2 = "world!!";
	printf("%s",ft_strjoin(s1,s2));
	return 0;
} */
