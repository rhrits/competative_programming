#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> smaller(const vector<int>& arr) {
    vector<int> output;
    stack<int> s;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            output.push_back(-1);
        } else {
            output.push_back(arr[s.top()]);
        }
        s.push(i);
    }

    return output;
}

int main() {
    vector<int> arr = {1, 6, 4, 12, 3, 8};

    vector<int> result = smaller(arr);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}