#include"libft.h"
#include<bsd/stdlib.h>
static int	ft_numberlen(int n)
{
	int	len;

	len = 0;
	if(n == 0)
		return (1);
	if(n < 0)
			len = len + 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);	
}
char	*ft_itoa(int n)
{
	int len = ft_numberlen(n);
	char *str;
	str = malloc(len + 1);
	long number = n;

	if(!str)
		return (NULL);

	str[len] = '\0';
	if(number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	if(number == 0)
		str[0] = '0';
	while(number > 0)
	{
		str[--len] = (number % 10) + '0';
		number = number / 10;
	}
	return (str);
}
int main(int argc, char const *argv[])
{

	return 0;
}
