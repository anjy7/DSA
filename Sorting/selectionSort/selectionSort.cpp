#include <iostream>
using namespace std;

void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int findMaxIndex(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[max] <= arr[i])
        {
            max = i;
        }
    }
    return max;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int last = n - i - 1;
        int max = findMaxIndex(arr, last);
        swap(arr, max, last);
    }
}

int main()
{
    int arr[] = {2, 3, 5, 6, 7, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}