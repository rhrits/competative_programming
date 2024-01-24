#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChangeDP(int amount, vector<int> coins, int N) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 7, 10};
    int amount = 15;
    int N = coins.size();

    cout << coinChangeDP(amount, coins, N) << endl;

    return 0;
}