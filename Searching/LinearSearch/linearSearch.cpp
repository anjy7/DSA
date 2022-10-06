#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};

    int ans = linearSearch(arr, 5, 2);

    cout << ans;
}