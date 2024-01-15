#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int arr[] = {-3, 0, 1, 3, 6, 8, 11, 14, 20, 25};
    int k = 5;

    int low = 0;
    int high = low + 1;

    while (high < n && low > -1)
    {
        int pos = arr[high] - arr[low];
        if (pos > k)
        {
            low++;
        }
        else if (pos < k)
        {
            high++;
        }
        else
        {
            cout << arr[low] << " " << arr[high] << "\n";
            low++;
            high++;
        }
    }

    return 0;
}