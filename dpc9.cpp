#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return ""; // Edge case: empty array

    string prefix = strs[0]; // take first string as prefix
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            // shrink prefix until it matches
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    if (result.empty())
        cout << "Output: \"\"" << endl; // explicitly show empty string
    else
        cout << "Output: " << result << endl;

    return 0;
}
