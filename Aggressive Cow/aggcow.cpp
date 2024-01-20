#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(const vector<int>& stalls, int cows, int min_distance) {
    int count = 1;
    int last_position = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - last_position >= min_distance) {
            count++;
            last_position = stalls[i];
        }
    }

    return count >= cows;
}

int largmin(const vector<int>& stalls, int cows) {
    int low = 0;
    int high = stalls.back() - stalls[0];
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (is_valid(stalls, cows, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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

        vector<int> stall_locations(n);
        for (int j = 0; j < n; ++j) {
            cin >> stall_locations[j];
        }

        sort(stall_locations.begin(), stall_locations.end());

        int result = largmin(stall_locations, c);
        cout << result << endl;
    }

    return 0;
}