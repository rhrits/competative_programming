
//using dp
#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 0;

    for(int i=2; i<=n; i++) {
        if(i%2 == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);
        if(i%3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);
        dp[i] = min(dp[i], dp[i-1] + 1);
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