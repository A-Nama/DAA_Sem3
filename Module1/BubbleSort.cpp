#include<iostream>
using namespace std;

void printArr(int arr[], int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

void BubbleSort(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    BubbleSort(A, size);
    printArr(A,size);
}