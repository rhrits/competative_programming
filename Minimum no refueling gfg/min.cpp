#include <bits/stdc++.h>
using namespace std;


int minRefuelStops(int T, int F,
				vector<vector<int> >& S)
{
	int N = S.size(), ans = 0;
	sort(S.begin(), S.end());

	// Initializing max heap
	priority_queue<int> pq;
	for (int i = 0; i <= N; i++) {
		int dist = i == N ? T : S[i][0];
		while (F < dist) {
			if (!pq.size())
				return -1;
			F += pq.top(), ans++;
			pq.pop();
		}
		if (i < N)
			pq.push(S[i][1]);
	}
	return ans;
}


int main()
{
	int target = 100;
	int M = 10;
	vector<vector<int> > stations = {
		{ 10, 60 }, { 20, 30 }, { 30, 30 }, { 60, 40 }
	};

	
	cout << minRefuelStops(target, M, stations);
	return 0;
}
