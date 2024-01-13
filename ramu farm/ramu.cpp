#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n = 4;
    int arr[4][4] = {{1, 2, 3, 1}, {2, 6, 4, 8}, {1, 3, 2, 7}, {2, 0, 1, 5}};
    int s[4][4] = {0};
    int ans = 0;

    s[0][0] = arr[0][0];

    for (int j = 1; j < n; j++)
    {
        s[0][j] = s[0][j - 1] + arr[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        s[i][0] = s[i - 1][0] + arr[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int q1 = s[i][j];
            int q2 = s[i][n - 1] - q1;
            int q3 = s[n - 1][j] - q1;
            int q4 = s[n - 1][n - 1] - (q1 + q2 + q3);
            int qrd[] = {q1, q2, q3, q4};

            int rohan = *min_element(qrd, qrd + 4);
            ans = max(rohan, ans);
        }
    }

    cout << ans;

    return 0;
}