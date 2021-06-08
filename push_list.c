
#include "header.h"

void	li_insert(t_head *head, int data)
{
	t_li	*new;
	t_li	*last;

	new = (t_li*)malloc(sizeof(t_li));
	new->data = data;
	new->next = NULL;
	if (head->fir == NULL)
	{
		head->fir = new;
		return ;
	}
	last = head->fir;
	while (last->next != NULL)
		last= last->next;
	last->next = new;
}

void	li_print(t_head *head)
{
	t_li	*new;
	char	*tmp;
	int		len;

	new = (t_li*)malloc(sizeof(t_li));
	new = head->fir;
	while (new->next != NULL)
	{
		tmp = ft_itoa(new->data);
		len = ft_strlen(tmp);
		write(1, tmp, len);
		write(1, "\n", 2);
		new = new->next;
	}
	tmp = ft_itoa(new->data);
	len = ft_strlen(tmp);
	write(1, tmp, len);
	write(1, "\n", 2);
}
