#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("Do_thi.txt", "r");
    if(file == NULL)
    {
        printf("Khong the mo.");
        return;
    }

    int n;
    if(fscanf(file, "%d", &n) != 1)
    {
        fclose(file);
        return;
    }

    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}