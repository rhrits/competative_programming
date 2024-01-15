#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    int arr[] = {5, 1, 3, 8, 7, 2, 6, 9};
    int k = 14;

    for (int x : arr)
    {
        if (s.count(k - x))
        {
            cout << x << " " << k - x << "\n";
        }
        s.insert(x);
    }

    return 0;
}