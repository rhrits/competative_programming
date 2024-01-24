#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    while (true) {
        
        cin >> N;

        if (N == -1) {
            
            break;
        }

        vector<int> jobs(N);
        int totalJobs = 0;

        for (int i = 0; i < N; ++i) {
            cin >> jobs[i];
            totalJobs += jobs[i];
        }

        int targetLoad = totalJobs / N;

        int rounds = 0;

        while (true) {
            int maxLoad = *max_element(jobs.begin(), jobs.end());
            int minLoad = *min_element(jobs.begin(), jobs.end());

            if (maxLoad <= targetLoad) {
                break; 
            }

            for (int i = 0; i < N; ++i) {
                if (jobs[i] > targetLoad) {
                    jobs[i]--;
                    jobs[(i + 1) % N]++;
                }
            }

            rounds++;
        }

        cout << rounds << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
