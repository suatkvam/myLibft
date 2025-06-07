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
/* 
char	**ft_split(char const *s, char c)
{
	char **temp;
	int i; // split index
	int j; //string index
	int word_len;

	i = 0;
	j = 0;
	if(!s) return(NULL);
	temp = malloc(sizeof(char*) * (ft_count_word(s,c) + 1));
	if (!temp) return NULL;
	while (s[i] && j < ft_count_word(s,c))
	{	
		while (s[i] == c) i = i + 1;
		if(s[i] == '\0') break;
		word_len = ft_get_word_len(s + i,c);
		temp[j] = ft_substr(s,i,word_len);
		if(!temp[j])
			{
				ft_split_free(temp);
				return NULL;	
			}
		j = j + 1;
		i = i + word_len;
	}
	temp[j] = NULL;
	return temp;
}
 */
char	**ft_split(char const *s, char c)
{
	char **res;
	int i; // split_index
	int j; // string index
	int word_len;
	i = 0;
	j = 0;
	word_len = 0;
	res = malloc(sizeof(char*) * (ft_count_word(s,c) + 1));
	if (!res)
		return NULL;
	while (s[i] && j < ft_count_word(s,c))
	{	
		while (s[i++] == c)
		if(s[i] == '\0')
			break;
		word_len = ft_get_word_len(s + i,c);
		res[j++] = ft_substr(s,i,word_len);
		if(!res[j])
		{
			ft_split_free(res);
			return NULL;	
		}
		i = i + word_len;
	}
	res[j] = NULL;
	return res;
}
// 