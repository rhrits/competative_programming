#include <iostream>
#include <vector>

using namespace std;

void uniqueno(const vector<int>& arr) {
    int xorResult = 0;

    for (int num : arr) {
        xorResult ^= num;
    }


    

    
    int rightmostSetBit = xorResult & -xorResult;

    int uniqueNum1 = 0;
    int uniqueNum2 = 0;

    
    for (int num : arr) {
        if ((num & rightmostSetBit) == 0) {
            uniqueNum1 ^= num;
        } else {
            uniqueNum2 ^= num;
        }
    }

    cout << uniqueNum1 << " and " << uniqueNum2 ;
}

int main() {
    vector<int> arr = {5, 7, 3, 2, 11, 3, 5, 2};

    uniqueno(arr);

    return 0;
}
