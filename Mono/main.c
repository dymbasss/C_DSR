//Монотонная последовательность
#include "header.h"
#define N 20 // количество элементов

int fib_n(int n)
{
	int x = 1;
	int y = 0;
	for (int i = 1; i < n; i++)
	{	
		x += y;
		y = x - y;
		if( x % 2 == 0)
		{
			x = 0+rand()%100;
		}

	} 
	return x;
}

int main()
{
	FILE *fp; 
	char *name = "/home/fox/DSR/Mono/fib.txt";
	char *name2 = "/home/fox/DSR/Mono/mono.txt";
	int size;
	int *mass = (int*)malloc(N * sizeof(int));

	fp = fopen(name, "w+");
	if( fp == NULL)
		exit(1);
	
	for(int i = 1; i <= N; i++)
	{
		fprintf(fp, " %d", fib_n(i));
	}

	rewind(fp);

	int n = 0;

	while (fscanf(fp,"%d",&(mass[n])) != EOF)
	{
		n++;
	}

	fclose(fp);

	fp = fopen(name2, "w");
	if( fp == NULL)
		exit(1);

	for (int j = 0; j < N; j++)
	{
		if (j == 0)
		{
			mass[j-1] = 0; 
		}
		if (j == N-1)
		{
			mass[j+1] = mass[j] + 1;
		}

		if (mass[j] <= mass[j+1] && mass[j] >= mass[j-1])
		{ 
			fprintf(fp, " %d", mass[j]);
		}
		else {mass[j] = mass[j-1];} 
	}
	free(mass);
	fclose(fp);

	return 0;
}
