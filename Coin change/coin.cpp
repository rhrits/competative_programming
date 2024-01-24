#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int coinChangeRec(int amount, vector<int> coins, int N) {
    if(amount == 0)
        return 0;

    int ans = INT_MAX;

    for(int i = 0; i < N; i++) {
        if (amount-coins[i] >= 0) {
            int subprob = coinChangeRec(amount-coins[i], coins, N);
            ans = min(ans, subprob + 1);
        }
    }

    return ans;
}

int main() {
    vector<int> coins = {1, 7, 10};
    int amount = 15;
    int N = coins.size();

    cout << coinChangeRec(amount, coins, N) << endl;

    return 0;
}