#include <iostream>
using namespace std;

int findMax(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[max] <= arr[i])
        {
            max = i;
        }
    }
    return arr[max];
}

void countSort(int arr[], int n)
{
    int count[10];
    int output[10];
    int max = findMax(arr, n);

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {6, 5, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array: \n";
    display(arr, n);
    countSort(arr, n);
    
    display(arr, n);
    return 0;
}