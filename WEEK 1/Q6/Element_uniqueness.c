#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int hasDuplicate(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                return 1;
        }
    }

    return 0;
}

int main()
{
    srand(time(NULL));

    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);

    printf("\nGenerated Array:\n");

    // Small range intentionally increases the chance of duplicates
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    if (hasDuplicate(arr, n))
        printf("Duplicate elements found.\n");
    else
        printf("All elements are unique.\n");

    return 0;
}
