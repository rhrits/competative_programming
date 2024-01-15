
#include<iostream>

using namespace std;





int main() {
    vector<int> arr = {1, 6, 4, 12, 3, 8};

    vector<int> nextSmaller = SmallerElements(arr);

    
    for (int i : nextSmaller) {
        cout << i << " ";
    }

    return 0;
}