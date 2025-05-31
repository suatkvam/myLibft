#include "libft.h"
#include<stdio.h>


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	i = 0;
	tmp_src = (unsigned char*)src;
	tmp_dst = dest;
	while(i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dest);

}
// int main(int argc, char const *argv[])
// {
// 	char src[] = "Hello, world!!!!"; 
// 	char dest[] = "dünya";
// 	// ft_memcpy(dest,src,10);
// 	printf("%s",dest);
	
// 	return 0;
// }
