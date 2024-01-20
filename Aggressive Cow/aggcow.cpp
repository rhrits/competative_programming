#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(const vector<int>& stalls, int c, int md) {
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - last_pos >= md) {
            count++;
            last_pos = stalls[i];
        }
    }

    return count >= c;
}

int largmin(const vector<int>& stalls, int c) {
    int s = 0;
    int e = stalls.back() - stalls[0];
    int result = -1;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (is_valid(stalls, c, mid)) {
            result = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, c;
        cin >> n >> c;

        vector<int> stall_loc(n);
        for (int j = 0; j < n; ++j) {
            cin >> stall_loc[j];
        }

        sort(stall_loc.begin(), stall_loc.end());

        int result = largmin(stall_loc, c);
        cout << result << endl;
    }

    return 0;
}