#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countTripletsWithSumSmallerThanTarget(vector<int>& arr, int targetSum) {
    int n = arr.size();
    int count = 0;

    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

           if (currentSum <= targetSum) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
   
    vector<int> arr = {2, 1, 4, 6, 3, 8, 7};
    int targetSum = 11;

    int result = countTripletsWithSumSmallerThanTarget(arr, targetSum);

    cout << "Count of triplets with sum less than or equal to " << targetSum << ": " << result << endl;

    return 0;
}
