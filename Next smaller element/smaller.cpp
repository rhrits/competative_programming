
#include<iostream>

using namespace std;
vector<int> output;
stack<int> s;

for(i=0; i<n; i++){
    while(s.empty() && stop() >= arr[i]){
        s.pop();
    }
    if(s.empty())
    {
        output.push_back(-1);
    }
        {
            else{
                ans.push_back(stop());
            }
        }

    s.push(arr[i]);    
    }

    





int main() {
    vector<int> arr = {1, 6, 4, 12, 3, 8};

    vector<int> nextSmaller = SmallerElements(arr);

    
    for (int i : nextSmaller) {
        cout << i << " ";
    }

    return 0;
}