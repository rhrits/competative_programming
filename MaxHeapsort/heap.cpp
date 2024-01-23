#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {7, 3, 8, 5, 2, 1};  
    int n = sizeof(arr) / sizeof(arr[0]);  

   
    make_heap(arr, arr + n);

    cout << "Max heap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
