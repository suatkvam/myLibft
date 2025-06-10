 #include"libft.h"

 static void	ft_putchar_fd(char c, int fd)
{
	write(fd,&c,1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-',fd);
		n = -n;
	}
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10,fd);
		n = n % 10;
		
	}
	ft_putchar_fd(n + '0',fd);
}