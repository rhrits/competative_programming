#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customCompare(int x, int y) {
    string xy = to_string(x) + to_string(y);
    string yx = to_string(y) + to_string(x);
    return xy > yx;
}

string largestNumber(vector<int>& nums) {   
    sort(nums.begin(), nums.end(), customCompare);
    string result;
    for (int num : nums) {
        result += to_string(num);
    }
    return result;
}

int main() {
    vector<int> numbers1 = {1, 33, 332};
    cout << "Largest number: " << largestNumber(numbers1) << endl;

    return 0;
}
