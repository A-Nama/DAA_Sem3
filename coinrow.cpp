#include <iostream>
using namespace std;

int coinRow(int coins[], int n) {
    if (n == 0) return 0;
    if (n == 1) return coins[0];
    if (n == 2) return max(coins[0], coins[1]);

    int dp[n];
    bool include[n]; // Array to keep track of whether a coin is included in the solution

    dp[0] = coins[0];
    include[0] = true;
    
    dp[1] = max(coins[0], coins[1]);
    include[1] = (coins[1] > coins[0]);

    for (int i = 2; i < n; ++i) {
        if (coins[i] + dp[i - 2] > dp[i - 1]) {
            dp[i] = coins[i] + dp[i - 2];
            include[i] = true;
        } else {
            dp[i] = dp[i - 1];
            include[i] = false;
        }
    }

    // Backtracking to print the coins included in the maximum value collection
    cout << "Coins included in the maximum value collection: ";
    for (int i = n - 1; i >= 0;) {
        if (include[i]) {
            cout << coins[i] << " ";
            i -= 2; // Skip the adjacent coin as it's not allowed to be picked
        } else {
            i -= 1; // Move to the previous coin
        }
    }
    cout << endl;

    return dp[n - 1];
}

int main() {
    int no;
    cout << "Enter no. of coins you have: \n";
    cin >> no;
    
    int coins[no];
    cout << "Enter the values of the coins in order: \n";
  
    for (int i = 0; i < no; i++) {
        cin >> coins[i];
    }
 
    int result = coinRow(coins, no);
    
    cout << "The maximum value that can be collected is " << result << "." << endl;
    
    return 0;
}
