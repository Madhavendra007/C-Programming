#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, store_temp;
    printf("Enter size(n) of the Matrix: ");
    scanf("%d", &size);
    int *arr1 = (int *)malloc(size * size * sizeof(int));
    int *arr2 = (int *)malloc(size * size * sizeof(int));
    int *arr3 = (int *)malloc(size * size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter element at position %d , %d: ", i + 1, j + 1);
            scanf("%d", &store_temp);
            *(arr1 + i * size + j) = store_temp;
        }
    }
    printf("\n----------------------------------\n");
    printf("The elements of matrix 1 are:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *(arr1 + i * size + j));
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter element at position %d , %d: ", i + 1, j + 1);
            scanf("%d", &store_temp);
            *(arr2 + i * size + j) = store_temp;
        }
    }
    printf("\n----------------------------------\n");
    printf("The elements of matrix 2 are:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *(arr2 + i * size + j));
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(arr3 + i * size + j) = 0;
            for (int k = 0; k < size; k++)
            {
                *(arr3 + i * size + j) = *(arr3 + i * size + j) + *(arr1 + i * size + k) * *(arr2 + k * size + j);
            }
        }
    }

    printf("\n----------------------------------\n");
    printf("The multiplied matrix elements are:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *(arr3 + i * size + j));
        }
        printf("\n");
    }

    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}