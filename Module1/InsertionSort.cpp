#include<iostream>
using namespace std;

void InsertionSort(int arr[], int size){
    for(int i = 1; i<size; i++){
        int j = i - 1;
        int key = arr[i];

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    InsertionSort(A, size);

    for(int i = 0; i<size; i++){
        cout<<A[i]<< " ";
    }
    cout<<endl;
}