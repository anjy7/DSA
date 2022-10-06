#include <iostream>
using namespace std;

int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start];
    for (int j = start + 1; j <= end; j++)
    {
        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    swap(A[start], A[i - 1]);
    return i - 1;
}

void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int piv_pos = partition(A, start, end);
        quick_sort(A, start, piv_pos - 1);
        quick_sort(A, piv_pos + 1, end);
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
    int arr[] = {6, 5, 12, 10, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: \n";
    display(arr, n);

    quick_sort(arr, 0, n - 1);

    cout << "Sorted array: \n";
    display(arr, n);
    return 0;
}