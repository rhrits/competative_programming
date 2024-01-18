#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void uniqueno(const vector<int>& arr) {
    unordered_set<int> seen;
    unordered_set<int> uniqueNumbers;

    for (int num : arr) {
        if (seen.count(num) == 0) {
            seen.insert(num);
            uniqueNumbers.insert(num);
        } else {
            uniqueNumbers.erase(num);
        }
    }

    
    for (int uniqueNum : uniqueNumbers) {
        cout << uniqueNum << " ";
    }
}

int main() {
    vector<int> arr = {5, 7, 3, 2, 11, 3, 5, 2};

    uniqueno(arr);

    return 0;
}
