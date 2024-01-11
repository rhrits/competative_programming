#include <iostream>
using namespace std;

int pow(int num, int power);

int main()
{
    int num, power, ans;
    cin >> num >> power;

    ans = pow(num, power);
    cout << ans;
}

int pow(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }

    int t = pow(num, power / 2);
    t *= t;

    if (power % 2 == 0)
    {

        return t;
    }
    else
    {
        return t * num;
    }
}