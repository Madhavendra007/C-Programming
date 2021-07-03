#include <stdio.h>
#include <stdlib.h>

int size;

int findMaxElem(int array[])
{
    int highest = 0;

    for (int i = 0; i < size; i++)
    {
        if (highest < array[i])
        {
            highest = array[i];
        }
    }

    return highest;
}

int main()
{
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter a positive element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    int highest = findMaxElem(arr);
    printf("%d", highest);

    free(arr);
    return 0;
}