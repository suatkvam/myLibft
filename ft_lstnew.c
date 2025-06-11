#include"libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *node;
	node = malloc(sizeof(t_list) + 1);
	if(!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return node;
	
}

int main(int argc, char const *argv[])
{
	char *str = "deneme1";
	char *str2 = "deneme2";

	t_list * a = ft_lstnew(str);

	a->next = ft_lstnew(str2);
	// a->next->next = a;
	/* printf("%s \n",(char *)a->content);
	printf("%s\n",(char *) a->next ->content); */
	int i = 0;

	while (i++ <= 100)
	{
		printf("%s\n",(char *)a ->content);
		if(a->next == NULL)
			break;
		a = a->next;
		
	}
	

	return 0;
}
