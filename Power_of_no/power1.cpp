//pow(x, n) using recursion


#include <iostream>
using namespace std;

int power(int x, int n)
{
    // If x^0 return 1
    if (n == 0)
        return 1;
    // If we need to find of 0^y
    if (x == 0)
        return 0;
    // For all other cases
    return x * power(x, n - 1);
}

int main()
{
    int x, n;

    // Taking input for x
    cout << "Enter the value of x: ";
    cin >> x;

    // Taking input for n
    cout << "Enter the value of n: ";
    cin >> n;

    // Function call
    cout << "Result: " << power(x, n) << endl;

    return 0;
}
