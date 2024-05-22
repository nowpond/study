#include <stdio.h>
#include <time.h>
#define COL 5
#define ROW 5

void generateMatrix(int* mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(mat + i) = rand() % 11 - 5;
    }
}

void printMatrix(int* mat, int n)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", *(mat + i * n + j));
        }
        printf("\n");
    }
    printf("\n");
}

void multiplyMatrix(int* mat1, int* mat2, int* result, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                *(result + i * n + j) += *(mat1 + i * n + k) * *(mat2 + k * n + j);
        }
    }
}

int main(void)
{
    int arr1[ROW][COL] = { 0 }, arr2[ROW][COL] = { 0 }, arr3[ROW][COL] = { 0 };
    srand(time(NULL));
    generateMatrix(arr1, 25);
    generateMatrix(arr2, 25);

    printf("Matrix 1\n");
    printMatrix(arr1, 5);

    printf("Matrix 2\n");
    printMatrix(arr2, 5);

    multiplyMatrix(arr1, arr2, arr3, 5);
    printf("Matrix multiplication\n");
    printMatrix(arr3, 5);
    return 0;
}