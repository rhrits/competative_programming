#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> SmallerElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  
    stack<int> st;  

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 6, 4, 12, 3, 8};

    vector<int> nextSmaller = SmallerElements(arr);

    
    for (int i : nextSmaller) {
        cout << i << " ";
    }

    return 0;
}
