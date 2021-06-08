
#include "header.h"

void    check_num(char  *str)
{
    long long   num;

    if (str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
    {
        write(1, "Error\n", 7);
        exit (1);
    }
    num = ft_atoi2(str);
    if (num > 2147483647 || num < -2147483648)
    {
        write(1, "Error\n", 7);
        exit (1);
    }
}

int	main(int argc, char *argv[]) // insert
{
	//t_li	*li;
	t_head	*head;
	int		i;
	int		num;

	i = 1;
	head = (t_head*)malloc(sizeof(t_head*));
	//li = (t_li*)malloc(sizeof(t_li));
	//li->next = NULL;
	//head->fir = li;
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		check_num(argv[i]);
		num = ft_atoi(argv[i]);
		li_insert(head, num); //
		i++;
	}
	li_print(head);
}
