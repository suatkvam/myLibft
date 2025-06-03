#include"libft.h"

static int ft_count_word(const char *str, char c)
{
	int count = 0;
	int in_word = 0;

	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
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
static int ft_get_word_len(const char *s, char c)
{
	int len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return len;
}
static void ft_split_free(char **split)
{
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i = i+ 1;
	}
	free(split);
}
char	**ft_split(char const *s, char c)
{
	char **temp;
	int split_index;
	int string_index;
	int word_len;
	split_index = 0;
	string_index = 0;
	word_len = 0;
	int count_word_len = ft_count_word(s,c);	
	temp = malloc(sizeof(char*) * (count_word_len + 1));
	if (!temp)
		return NULL;
	while (s[split_index] != '\0')
	{
		while (s[split_index] == c)
			split_index = split_index + 1;
		if(s[split_index] == '\0')
			break;
		word_len = ft_get_word_len(s + split_index,c);
		temp[string_index] = ft_substr(s,split_index,word_len);
		if(!temp[string_index])
			{
				ft_split_free(temp);
				return NULL;	
			}
		string_index = string_index + 1;
		split_index = split_index + word_len;
	}
	temp[string_index] = NULL;
	return temp;
}
