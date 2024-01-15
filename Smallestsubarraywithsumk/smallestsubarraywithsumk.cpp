
#include <iostream>
using namespace std;


int smallestSubarraySumK(int arr, int k)
{
	int result = INT_MAX;

	for (int i = 0; i < arr.size(); ++i) {
		int sum = 0;
		for (int j = i; j < arr.size(); j++) {
			sum += arr[j];
			if (sum == k) {
				result = min(result, (j - i + 1));
			}
		}
	}

	
	return result;
}


int main()
{

	int arr = { 1, 3, 2, 1, 4, 1, 3, 2, 1, 6, 2 };
	int k = 8;

	int result = smallestSubarraySumK(arr, k);
	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;
	return 0;
}
