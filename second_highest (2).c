#include <stdio.h>
#include <stdlib.h>

void inputarray(int arr[], int total_index)
{
    for (int i = 0; i < total_index; i++)
    {
        printf("Enter a positive element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int size;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    inputarray(arr, size);

    int highest = 0, second_highest = 0;

    for (int i = 0; i < size; i++)
    {
        if (highest < arr[i])
        {
            second_highest = highest;
            highest = arr[i];
        }

        else if (second_highest < arr[i] && highest >= arr[i])
        {
            second_highest = arr[i];
        }
    }

    printf("\nSecond Highest Element is: %d\n", second_highest);

    free(arr);
    return 0;
}