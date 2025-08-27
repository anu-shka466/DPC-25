#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) {
        return s;
    }
    
    int start = 0;
    int max_len = 1;
    
    for (int i = 0; i < n; i++) {
        // Check for odd-length palindromes with center at i
        int left = i;
        int right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > max_len) {
                start = left;
                max_len = right - left + 1;
            }
            left--;
            right++;
        }
        
        // Check for even-length palindromes with center between i and i+1
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > max_len) {
                start = left;
                max_len = right - left + 1;
            }
            left--;
            right++;
        }
    }
    
    return s.substr(start, max_len);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    if (input.empty()) {
        cout << " " << endl;
        return 1;
    }
    
    string result = longestPalindrome(input);
    
    cout << "Longest palindromic substring: " << result << endl;
    cout << "Length: " << result.length() << endl;
    
    return 0;
}