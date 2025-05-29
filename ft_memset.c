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

// #include"libft.h"

// /*this function sets each byte of to*/
// /*the memory area pointed to by s to the given byte c*/
// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*tmp;

// 	i = 0;
// 	tmp = s;
// 	while (i < n)
// 	{
// 		tmp[i] = (unsigned char) s;
// 		i = i + 1;
// 	}
// 	return (s);
// }
// int main()
// {
  
//   int a[0] = {5};
//   size_t size = 2;
//   ft_memset(a,c,size);
// 	 printf("%d",a[0]);

// //   int num;
// //   int n2 = 7;
// //   size_t size2 = 3;

// //   ft_memset(num ,255, 4);
// //   ft_memset(num ,247, 1);

// //   num
// //   printf("%d",num)
// }