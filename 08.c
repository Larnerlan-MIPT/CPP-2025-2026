#include <stdio.h>

void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    reverse(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}