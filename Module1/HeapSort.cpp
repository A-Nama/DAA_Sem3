#include<iostream>
using namespace std;

//swap function
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void buildMaxheap(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[(i - 1) / 2]){
            int j = i;

            while (arr[j] > arr[(j - 1) / 2]){
                swap(arr, j, (j - 1) / 2);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapsort(int arr[], int n){
    buildMaxheap(arr, n);

    for (int i = n - 1; i > 0; i--){
        swap(arr, 0, i);

        int j = 0;
        int index;
        do{
            index = (2 * j) + 1;
            if (index < (i - 1) && arr[index] < arr[index + 1]){
                index++;
            }
            if (index < i && arr[j] < arr[index]){
                swap(arr, j, index);
                j = index;
            }
        } while (index < i);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Given array: ";
    for (int i = 0; i < n; i++)
         cout << arr[i] << " ";

    cout << endl;

    heapsort(arr, n);

    // print array after sorting
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}