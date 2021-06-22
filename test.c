#include <stdio.h>

int	main()
{
	int i = 0;
	int j = 2;

	while (j < 4)
	{
		while (i++ < j)
			printf("%d\n", i);
		printf("out %d\n", i);
		j++;
	}
}
