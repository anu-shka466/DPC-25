#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right && s[left] == ' ') left++;
    while (right >= left && s[right] == ' ') right--;

    vector<string> words;
    string word = "";

    for (int i = left; i <= right; i++) {
        if (s[i] == ' ') {
            if (!word.empty()) {
            
                words.push_back(word);
                word = "";
            }
        } else {
            word += s[i];
        }
    }
    if (!word.empty()) {
        
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) result += " ";
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);   // ✅ take full line

    string ans = reverseWords(s);
    cout << "Reversed words: " << ans << endl;
    return 0;
}
