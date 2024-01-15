#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int arr[] = {2, 1, 4, 6, 3, 8, 7};
    int k = 11;
    int count = 0;

    int first = 0;

    while (first < n)
    {
        int second = first + 1;
        int third = n - 1;

        while (second < third)
        {
            int pos = arr[first] + arr[second] + arr[third];

            if (pos > k)
            {
                third--;
            }
            else
            {
                cout << arr[first] << " " << arr[second] << " " << arr[third] << "\n";
                count++;
                second++;
            }
        }

        first++;
    }

    cout << count;

    return 0;
}