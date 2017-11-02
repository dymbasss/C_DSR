//Монотонная последовательность
#include "header.h"
#define N 30

int fib_n(int n)
{
	int x = 1;
	int y = 0;
	for (int i =1; i < n; i++)
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
	char *name = "/home/fox/Mono/fib.txt";
	char *name2 = "/home/fox/Mono/mono.txt";
	int n = 0, y = 0;
	char c;

	fp = fopen(name, "w+");
	if( fp == NULL)
		exit(1);

	for(int i = 1; i <= N; i++)
	fprintf(fp, " %d", fib_n(i));

	rewind(fp);

	int mass[N];
	while (fscanf(fp,"%d",&(mass[n])) != EOF)
	{
		n++;
	}
	fclose(fp);

	fp = fopen(name2, "w");
	if( fp == NULL)
		exit(1);

	int m = N;

	for (int j = 0; j < m; j++)
	{
		if (mass[j] <= mass[j+1] && mass[j] >= mass[j-1])
		{ 
			fprintf(fp, " %d", mass[j]);
		}
		else {mass[j] = mass[j-1];}
		
	}

	fclose(fp);
	return 0;
}
