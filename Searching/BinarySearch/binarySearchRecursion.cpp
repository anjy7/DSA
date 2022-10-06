// Binart Search using Recursion

#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
    int mid = start + (end - start) / 2;

    while (start < end)
    {

        if (target == arr[mid])
        {
            return mid;
        }

        if (target < arr[mid])
        {
            binarySearch(arr, start, mid - 1, target);
        }
        else
        {
            binarySearch(arr, mid + 1, end, target);
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int start = 0;
    int end = 8;
    int ans = binarySearch(arr,start,end,5);

    cout << ans;
}