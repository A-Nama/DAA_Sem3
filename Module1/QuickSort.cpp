#include<iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; 
    int i = left - 1; 

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[right]);
    return i + 1; 
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
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

    quickSort(A, 0, size-1);

    for(int i = 0; i<size; i++){
        cout<<A[i]<< " ";
    }
    cout<<endl;
}