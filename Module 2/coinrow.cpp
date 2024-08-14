#include <iostream>
using namespace std;

int coinRow(int coins[], int n) {

    if (n == 0) return 0;
    if (n == 1) return coins[0];
    if (n == 2) return max(coins[0], coins[1]);

    int dp[n];
    
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);
    

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], coins[i] + dp[i-2]);
    }
    
    return dp[n-1];
}

int main() {
    int no;
    cout<<"Enter no. of coins you have: \n";
    cin>>no;
    
    int coins[no];
    cout<<"Enter the values of the coins in order: \n";
  
    for(int i = 0; i<no; i++){
    	cin>>coins[i];
    }
 
    int result = coinRow(coins, no);
    
    cout<<"The maximum value that can be collected is "<<result<<"."<<endl;
    
    return 0;
}
