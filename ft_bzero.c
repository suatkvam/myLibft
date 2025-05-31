#include"libft.h"
#include<strings.h>
#include<stdio.h>
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = (unsigned char) 0;
		i = i + 1;
	}
}

// #include <stdio.h>
// #include <strings.h>

// int main(int argc, char const *argv[]) {
//     char a[5] = {'1', '2', '3', '4', '\0'};
//     bzero(a, 4);  // Zero out the first 4 characters
    
//     // Print individual characters as integers (ASCII values)
//     for (int i = 0; i < 5; i++) {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }
