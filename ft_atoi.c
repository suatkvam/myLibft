#include"libft.h"
#include<stdio.h>
int	ft_atoi(char *nptr)
{
	int i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] == 32 )||( nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sign = sign * -1;
	
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0'); 
		i++;
	}
	return num * sign;
}
int main()
{
	printf("%d",ft_atoi("--1234abcd"));
	return 0;
}
