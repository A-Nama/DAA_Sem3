#include<iostream>
using namespace std;

int knapsack(int W, int w[], int v[], int n){
    int K[100][100];
    for (int i = 0; i<=n; i++){
        for(int j = 0; j<=W; j++){
            if(i==0||j==0){
                K[i][j] = 0;
            }
            else if (w[i - 1] <= j) {
                K[i][j] = max(K[i - 1][j], v[i - 1] + K[i - 1][j - w[i - 1]]);
            }
            else{
                K[i][j] = K[i-1][j];
            }
        }
    }
    // Backtracking to find the items included in the knapsack
    int res = K[n][W];
    int w_rem = W;
    cout << "Items included in the knapsack: ";

    for (int i = n; i > 0 && res > 0; i--) {
        // Check if the item was included by comparing current value with the value above
        if (res != K[i - 1][w_rem]) {
            cout << "Item " << i << " (weight: " << w[i - 1] << ", value: " << v[i - 1] << ") ";
            // Subtract the item's value and reduce the remaining weight
            res -= v[i - 1];
            w_rem -= w[i - 1];
        }
    }
    cout << endl;
    cout<<"Maximum value of knapsack: ";
    return K[n][W];
}

int main(){
    int n = 4;
    int W = 7;
    int w[] = {1, 3, 4, 5};
    int v[] = {1, 4, 5, 7};
    cout << knapsack(W, w, v, n) << endl;
}
