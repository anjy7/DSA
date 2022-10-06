#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int start = 0;
    int end  = n;

    int mid = start + (end-start)/2;

    while(start<end){
        if(target == arr[mid]){
            return mid;
        }
        if(target<arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1; 
        }
    }
    
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};

    int ans = binarySearch(arr,8,5);

    cout<<ans;
}