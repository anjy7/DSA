#include <iostream>
using namespace std;

void BS(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 566, 1, 53, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array: " << endl;
    display(arr, n);
    BS(arr, n);
    cout << "Sorted array: \n";
    display(arr, n);
    return 0;
}
