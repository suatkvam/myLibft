#include"libft.h"

static int ft_count_word(const char *str)
{
	int count = 0;
	int in_word = 0;

	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		 in_word = 0; // boşluk görğnce kelime biter
		else if(in_word == 0)
		{
			in_word = 1;
			count ++;	
		}
		i++;
	}
	return count;
}
static int word_len(const char *s, char c)
{
	
}

char	**ft_split(char const *s, char c)
{
	int **temp;
	int count_word_len = ft_count_word(s);
	temp = malloc(sizeof(char*) * (count_word_len + 1));

}