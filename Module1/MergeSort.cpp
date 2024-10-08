#include<iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right - left) /2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        Merge(arr, left, mid, right);
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

    MergeSort(A, 0, size-1);

    for(int i = 0; i<size; i++){
        cout<<A[i]<< " ";
    }
    cout<<endl;
}