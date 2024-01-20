#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void subsetinrange(vector<int>& arr, int A, int B) {
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        int low = i + 1, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currentSum = arr[i] + arr[mid];

            if (currentSum >= A && currentSum <= B) {
                
                cout << "Subset: " << arr[i] << " " << arr[mid] << endl;
            }

            if (currentSum > B) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
}

int main() {
    
    vector<int> arr = {1, 2, 3, 0, 5, 6, -2, 8};
    
    int A = 4;
    int B = 7;

    
    subsetinrange(arr, A, B);

    return 0;
}
