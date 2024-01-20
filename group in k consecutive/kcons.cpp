
#include <bits/stdc++.h>
using namespace std;

bool groupInKConsecutive(vector<int>& arr,
						int K)
{
	
	map<int, int> count;

	for (int h : arr) {
		++count[h];
	}

	
	for (auto c : count) {
		int cur = c.first;
		int n = c.second;

	
		if (n > 0) {

			
			for (int i = 1; i < K; ++i) {

				
				if (!count.count(cur + i)) {
					return false;
				}

				count[cur + i] -= n;

				
				if (count[cur + i] < 0)
					return false;
			}
		}
	}

	return true;
}


int main()
{
	vector<int> arr = { 6, 8, 4, 2, 1, 7 };
	int k = 4;
	if (groupInKConsecutive(arr, k)) {
		cout << "True";
	}
	else {
		cout << "False";
	}
}




