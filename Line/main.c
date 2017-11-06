
#include "header.h"
#define N 3 // Количество уравнений

double *gauss (double **mat, double *x)
{
	double max, next;

	for (int k = 0; k < N; k++) //поиск максимального элемента в первом столбце
	{
		max = abs(mat[k][k]);
		int i = k;

		for (int m = k + 1; m < N; m++)
			if (abs(mat[m][k]) > max)
			{
				i = m;
				max = abs(mat[m][k]);
			}

		if (max == 0)   // проверка на нулевой элемент
		{
            printf("Решений нет!");
		}

		if (i != k) // перестановки i-ой строки, содержащий главный элемент k-ой строки
		{
			for (int j = k; j < N + 1; j++)
			{
				next = mat[k][j];
				mat[k][j] = mat[i][j];
				mat[i][j] = next;
			}
		}

		max = mat[k][k];  // преобразование k-ой строки 
		mat[k][k] = 1;

        for (int j = k + 1; j < N + 1; j++)
        {
            mat[k][j] = mat[k][j] / max;
        }
            
		for (i = k + 1; i < N; i++) // Преобразование строк с помощью k-ой строки
		{
			next = mat[i][k];
			mat[i][k] = 0;

			if (next != 0)
				for (int j = k + 1; j< N + 1; j++)
				{
					mat[i][j] = mat[i][j] - next * mat[k][j];
				}
		}
	}

	for (int i = N - 1; i >= 0; i--) // Нахождение решений СЛАУ
	{
		x[i] = 0;
		max = mat[i][N];

		for (int j = N; j > i; j--)
		{
			max = max - mat[i][j] * x[j];
		}
		x[i] = max;
	}
	
	return x;
}

double **create(double **mat)
{
	for (int i = 0; i < N; i++)
	{
		mat[i] = (double*)malloc((N + 1) * sizeof(double));
	}
	return mat;
}

void scan_fp(FILE *fp, double **mat)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N + 1; j++)
		{
			fscanf(fp,"%lf",&mat[i][j]); 
		}      
	}
}

void clearbuff (double **mat)
{
	for (int i = 0; i < N; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

int main ()
{
	FILE *fp;
	char *name = "/home/fox/DSR/Line/matrix.txt";
	double *x = (double*)malloc(N * sizeof(double));
	double **mat = (double**)malloc(N * sizeof(double*));
    create(mat);
    
	fp = fopen(name, "r");
	if( fp == NULL)
	{
		exit(1);
	}
	scan_fp(fp, mat);
	fclose(fp);
    gauss(mat, x);
	
	printf("Вывод :");
	for (int i = 0; i < N; i++)
	{
		printf("\n x[%d] = %f ",i+1 , x[i]);
	}
	clearbuff(mat);
	free(x);
    getchar();
}