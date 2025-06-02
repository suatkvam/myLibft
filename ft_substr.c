#include"libft.h"
#include<stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	str = (char*) s;
	char *temp;
	size_t s_len;

	if (!s || s[0] == '\0') 
		return (NULL);
	

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup("")); // start stringin sonundan büyükse boş str döndürür

	if ( len > s_len - start)
		len = s_len - start; // kalan karakter sayısı uzunluğu

	temp = (char*)malloc(len + 1 );
	if(!temp)
		return NULL;

		ft_memcpy(temp,s + start,len);
	temp[len] = '\0';
	return (temp);
}


int main(int argc, char const *argv[])
{
	char *str = "Merhaba dunya";
	unsigned int start = 0;
	size_t len = 7;
	
	printf("%s",ft_substr(str,start,len));

	return 0;
}
