#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    
    unordered_map<char, int> frequency;

    
    for (char c : s) {
        frequency[c]++;
    }

    
    for (int i = 0; i < s.length(); i++) {
        if (frequency[s[i]] == 1) {
            
            return i;
        }
    }

    
    return -1;
}

int main() {
    
    string s1 = "codingminutes";
    cout << "Example 1: " << firstUniqChar(s1) << endl;

    
    string s2 = "aabb";
    cout << "Example 2: " << firstUniqChar(s2) << endl;

    return 0;
}
