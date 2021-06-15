#include <stdio.h>
#include <stdlib.h>

void    lstswap(int *lst, int i, int j)
{
    int     tmp;

    tmp = lst[i];
    lst[i] = lst[j];
    lst[j] = tmp;
}

int partion(int *lst, int i, int j)
{
    int     x;
    int     a;
    int     b;

    x = lst[i];
    a = i + 1;
    b = j;
    while (a <= b)
    {
        while (lst[a] <= x && a <= j)
            a++;
        while (b >= (i + 1) && x <= lst[b])
            b--;
        if (a <= b)
            lstswap(lst, a, b);
    }
    lstswap(lst, a, b);
    return (b);
}

void    quicksort(int *lst, int i, int j)
{
    int     pv;

    if (i <= j)
    {
        pv = partion(lst, i, j);
        quicksort(lst, i, pv - 1);
        quicksort(lst, pv + 1, j);
    }
}


int	main()
{
	int i;
	int n;
	int arr[100];

	n = 10;
	for(i = 0 ; i < n ; i++)
		 arr[i]=rand()%1000;

	 printf("정렬전 배열 :");
	 for(i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
	 printf("\n");

    quicksort(arr,0,n-1);

	printf("정렬후 배열 :");
    for(i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
	printf("\n");

    return 0;
}
