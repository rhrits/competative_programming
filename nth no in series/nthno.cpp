#include <iostream>

using namespace std;

int main() {
    int n = 8; 
    int number;

    if (n % 3 == 1) {
        number = 1;
    } else if (n % 3 == 2) {
        number = 5;
    } else {
        number = 7;
    }

    cout << "The " << n << "th number in the sequence is: " << number << endl;

    return 0;
}
