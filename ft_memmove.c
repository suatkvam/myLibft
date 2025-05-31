/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:58:06 by akivam            #+#    #+#             */
/*   Updated: 2025/05/31 12:03:37 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include <string.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	i = 0;
	tmp_src = (unsigned char*)src;
	tmp_dst = (unsigned char*)dest;
	if (n == 0 || tmp_src == tmp_dst)
		return (dest);
		
	if (tmp_src > tmp_dst)
	{
		while(n--)
			tmp_dst[i] = tmp_src[i];
		
	}
	else if (tmp_dst > tmp_src)
	{	
		while (i < n)
		{
			tmp_dst[i] 	= tmp_src[i];
			i++;
		}
	}
	return (dest);
}
int main()
{
	unsigned char dest[] = "Hello, world!!!!";
    unsigned char src[] = "dünya";
    ft_memmove(dest, src, 5);  // ilk 5 karakteri taşır
    printf("%s\n", dest);  // Beklenen çıktı: "dünya, world!!!!"

	// tersine durum için

	unsigned char dest2[] = "Hello, world!!!!"; 
	unsigned char src2[] = "dünya";

	ft_memmove(dest2 + 6, src2, 5);  // 5 karakter "dünya"yı "world" üzerine taşır
	printf("%s\n", dest2);  // Beklenen çıktı: "Hello, dünya!!!!"
    return 0;
}
