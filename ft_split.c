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
		 in_word = 0; // c karakterine verilen şeyi görünce in word 1 artar
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
char **ft_split(char const *s, char c)
{
	char **res;
	int word_len;
	int word_count;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	word_count= ft_count_word(s, c);
	 res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	while (s[i] && j < word_count)
	{
		while (s[i] == c) i++;
		word_len = ft_get_word_len(s + i, c);
		res[j] = ft_substr(s, i, word_len);
		if (!res[j])
		{
			ft_split_free(res);
			return NULL;
		}
		i += word_len;
		j++;
	}
	res[j] = NULL;
	return res;
}
/* int main(int argc, char const *argv[])
{
	char * str = "ccccccccc gizem ccccccccc   arslanc";
	char c = 'c';
	char ** result = ft_split(str,c);

	if(result == NULL)
	{
		printf("ft_split returned NULL (memory allocation failed?)\n");
        return 1;
	}

	int i = 0;
	while(result[i] != NULL)
	{
		 printf("Part %d: %s\n", i, result[i]);
        i++;
	}
	i = 0;
    while (result[i] != NULL)
    {
        free(result[i]); // Her bir alt string'i serbest bırak
        i++;
    }
    free(result); // char ** dizisinin kendisini serbest bırak


	return 0;
}
 */