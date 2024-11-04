#include <iostream>
using namespace std;

int change(int coins[], int numCoins, int amount) {
    const int INF = 1001; // Represents infinity for this problem
    int dp[amount + 1];
    int lastCoin[amount + 1]; // Array to store the last coin used for each amount

    for (int i = 0; i <= amount; ++i) {
        dp[i] = INF;
        lastCoin[i] = -1; // Initialize with -1 to indicate no coin used initially
    }

    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    for (int i = 0; i < numCoins; ++i) {
        int coin = coins[i];
        for (int x = coin; x <= amount; ++x) {
            if (dp[x - coin] != INF && dp[x] > dp[x - coin] + 1) {
                dp[x] = dp[x - coin] + 1;
                lastCoin[x] = coin; // Store the coin used
            }
        }
    }

    // If we can't make the amount, return -1
    if (dp[amount] == INF) {
        return -1;
    }

    // Backtracking to find the coins used
    cout << "Coins used to make change: ";
    int currentAmount = amount;
    while (currentAmount > 0) {
        int coin = lastCoin[currentAmount];
        if (coin == -1) break; // No valid coin found, exit the loop

        cout << coin << " ";
        currentAmount -= coin; // Reduce the amount by the coin's value
    }
    cout << endl;

    return dp[amount];
}

int main() {
    int numCoins, amount;

    cout << "Enter number of coins: " << endl;
    cin >> numCoins;
    int coins[numCoins];

    cout << "Enter the coin values: " << endl;
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }

    cout << "Enter amount to make change: " << endl;
    cin >> amount;

    int changecoin = change(coins, numCoins, amount);

    if (changecoin == -1) {
        cout << "Can't make change with the given coins" << endl;
    } else {
        cout << "No. of coins needed to make change: " << changecoin << endl;
    }

    return 0;
}
