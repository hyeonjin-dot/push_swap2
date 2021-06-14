#include <stdio.h>

int	main()
{
	int i[3];

	i[0] = 1;
	i[1] = 3;
	i[2] = 2;
	if (i[0] < i[1])
	{
		if (i[1] > i[2])
			printf("1 3 2\n");
		else
			printf("1 2 3\n");
	}
	else
		printf("213\n");
	i[0] = i[0] + 3;
	printf("%d\n", i[0]);
}
