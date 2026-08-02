#include <stdio.h>

int findPartitionPoint(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements (only 0's followed by 1's):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int partition = findPartitionPoint(arr, n);

    if (partition == -1)
    {
        printf("\nThe array contains no 1's.\n");
    }
    else
    {
        printf("\nPartition Point = %d\n", partition);
        printf("Transition: arr[%d] = %d\n", partition, arr[partition]);
    }

    return 0;
}