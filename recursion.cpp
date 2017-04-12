#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define M 7
#define N 7

void fun(int **array, int m, int n, int x, int y)
{
#if 1
	if (
		(x==0||y==0||x==(m-1)||y==(n-1))||
		((array[x][y]<array[x-1][y])&&
		(array[x][y]<array[x][y-1])&&
		(array[x][y]<array[x+1][y])&&
		(array[x][y]<array[x][y+1])))
	{
		printf("球可以滚到：%d-%d\r\n", x, y);
		return ;
	}
	if (array[x][y]>=array[x-1][y])
	{
		fun(array, m, n, x-1, y);
	}
	if (array[x][y]>=array[x][y-1])
	{
		fun(array, m, n, x, y-1);
	}
	if (array[x][y]>=array[x+1][y])
	{
		fun(array, m, n, x+1, y);
	}
	if (array[x][y]>=array[x][y+1])
	{
		fun(array, m, n, x, y+1);
	}
#endif
}

int main()
{
	int **array;
	array = new int*[N];
	for (int k = 0 ; k<M; k++)
	{
		array[k] = new int[M];
	}
	srand(time(NULL));
	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j< M; j++)
		{
			array[j][i] = rand()%50;
			printf("%d\t", array[j][i]);
		}putchar('\n');
	}

	puts("-------------------\r\ninput x,y（位置,格式如 3,4）:");
	int m, n;
	scanf("%d,%d", &m, &n);
	fun(array, M, N, m, n);
}
