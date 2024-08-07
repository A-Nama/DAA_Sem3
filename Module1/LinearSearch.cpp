#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int search, int size){
    bool found = false;
    for(int i = 0; i<size; i++){
        if(arr[i]==search){
            cout<<"Element "<<search<<" found at index "<<i<<endl;
            found = true;
            break;
        }
    }
    return found;
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

    if (!LinearSearch(A,searchElement,size)){
        cout<<"Element not found in array"<<endl;
    }
    else{
        cout<<endl;
    }
}