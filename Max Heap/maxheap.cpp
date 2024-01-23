#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    vector<int> arr;

    Heap(int n = 16) {
        arr.resize(n); 
        arr[0] = -1;   
    }

    void push(int data) {
        
        arr.push_back(data);

       
        int index = arr.size() - 1;
        while (index > 1 && arr[index / 2] < data) {
            swap(arr[index], arr[index / 2]);
            index /= 2;
        }
    }

    

    void takeInputArray() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            push(data);
        }
    }
};

int main() {
    Heap heap;
    heap.takeInputArray();


    return 0;
}
