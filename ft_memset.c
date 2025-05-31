// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_memset.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/29 11:17:57 by akivam            #+#    #+#             */
// /*   Updated: 2025/05/29 18:37:45 by akivam           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = (unsigned char) c;
		i = i + 1;
	}
	return (s);
}
int main()
{
  
	// printf("%lu",a);
	// Print resulting bytes of the array
	// unsigned char *p = (unsigned char *)a;
	// for (int i = 0; i < sizeof(a); i++) {
		// 	printf("%02x ", p[i]);  // Print in hex to see exact byte values
		// }
	// 	printf("\n");
	// int a[7] = {1,2,3,4,5,6,7};
	// ft_memset(a, 12, 40);

    // for (int i = 0; i < 7; i++) {
    //     printf("a[%d] = %d\n", i, a[i]);
    // }

	printf("hata verecek 5 oldu için \n");
	int a2[11] = {7};
	ft_memset(a2, 12, 41);
	int i = 0;
	while (i < 10)
	{
		printf("%p\n", &a2[i]);
		i++;
	}
	printf("%d\n", a2[11]);




	// char str[] = "f";
	// char str2[] = "s";
	// printf("%p\n", str);
	// printf("%p\n", str2);
	// printf("%s\n", str + 6);

    return 0;


}