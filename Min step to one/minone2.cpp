// using bottom up dp


#include <bits/stdc++h>
using namespace std;
int minSteps(int n) {
    vector<int> dpn+1,0); // initialize dp array with all values as 0

    // initialize first value as 0, as no steps are required to reach 1
    dp[1] = 0;

    // iterate over the range [2, n]
    for (int i=2; i<=n; i++) {
        dp[i] = 1 + dp[i-1]; // assume that the minimum steps to reach i is by reducing it by 1

        // check if the number can be divided by 2 or 3, and if so, update the minimum steps
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Minimum steps required to minimize " << n << " to 1: " << minSteps(n) << endl;
    return 0;
}