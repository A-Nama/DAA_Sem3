#include<iostream>
using namespace std;

void SelectionSort(int arr[], int size){
    for(int i = 0; i<size; i++){
        int minIndex = i;
        for(int j = i+1; j<size; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }

        if (minIndex!=i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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

    SelectionSort(A, size);

    for(int i = 0; i<size; i++){
        cout<<A[i]<< " ";
    }
    cout<<endl;
}