#include "header.h"
#define N 50
#define S 2

void get_str(FILE *fp, char **str) // Получить стороки из файла
{
    int size = 0;
    while (size < N && fgets(str[size], N, fp))
        {
            char *p = strrchr(str[size], '\n');
            
            if (p)
            {
                *p = '\0';
            }
            size++;
        }
        fclose(fp);
}

char **create(char **str) // Выделение памяти
{
	for (int i = 0; i < N; i++)
	{
		str[i] = (char*)malloc(N * sizeof(char));
	}
	return str;
}

void get_word(char **str, char **word_mass, int number_str) // Получить массив слов из № строки 
{
    char *word = strtok(str[number_str], " ");
    int i = 0;

        while (word != NULL)
        {   
            word_mass[i] = word;
            word = strtok(NULL, " ");
            i++;
            word_mass[i] = '\0';
        }
    free(word);
}

void get_new_word(char **new_word_mass, char **word_mass) // Конкатенация слов в первой строке
{
    int i = 0;

        while (i < 4)
        {
                new_word_mass[i] = strcat(strcat(new_word_mass[i], word_mass[i]), word_mass[i + 1]);
                printf("%s ",new_word_mass[i]);
                i++;
        }
}
int main ()
{
    FILE *fp;
    char *name = "/home/fox/DSR/Konk/String";   
    char **str = (char**)malloc(S * sizeof(char*));
    char **word_mass = (char**)malloc(N * sizeof(char*));
    char **word_mass2 = (char**)malloc(N * sizeof(char*));
    char **new_word_mass2 = (char**)malloc(N * sizeof(char*));
    
    create(str);
    create(word_mass);
    create(word_mass2);
    create(new_word_mass2);

    fp = fopen(name,"r");
    if (fp == NULL)
    {
        exit(1);
    }

    get_str(fp, str);
    get_word(str, word_mass, 0);
    get_word(str, word_mass2, 1);
    get_new_word(new_word_mass2, word_mass);
    
        int i = 0;
        while (1)
        {
          if (word_mass[i] == '\0' || new_word_mass2[i] == '\0')
          {
              break;
          }

        for (int j = 0; word_mass2[j] != '\0'; j++)
        {
            if (strcmp(word_mass2[j], new_word_mass2[i]) != 0 && strlen(word_mass2[j]) != strlen(new_word_mass2[i]))
            {
                printf("\nНе cходятся: %s | %s", word_mass2[j], new_word_mass2[i]);
            }
        }
        i++;
    }
    getchar();      
}