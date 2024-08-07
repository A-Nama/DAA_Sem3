#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;

    while(left<= right){
        int mid = left + (right - left)/2;

        if(target==arr[mid]){
            return mid;
        }

        else if(target<arr[mid]){
            right = mid - 1;
        }

        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter size of the array A"<<endl;
    cin>>size;

    int A[size];

    cout<<"Enter elements of the array"<<endl;
    for(int i =0; i<size;i++){
        cin>>A[i];
    }

    int searchElement;
    cout<<"Enter element to be searched: "<<endl;
    cin>>searchElement;

    cout<<"Element found at index "<<BinarySearch(A, size, searchElement);
}