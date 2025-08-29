#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int lengthOfLongestSubstring(string S) {
    int n = S.size();
    int lastOccurrence[128];
    memset(lastOccurrence, -1, sizeof(lastOccurrence));
    int left = 0;
    int maxLength = 0;
    
    for (int right = 0; right < n; right++) {
        char c = S[right];
        if (lastOccurrence[c] >= left) {
            left = lastOccurrence[c] + 1;
        }
        lastOccurrence[c] = right;
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}

int main() {
    string S;
    cout<<"enter a string:"<<endl;
    cin >> S;
    cout << lengthOfLongestSubstring(S) << endl;
    return 0;
}