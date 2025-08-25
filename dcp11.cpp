#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void generatePermutations(string s, int start, vector<string>& result) {
    if (start == s.length() - 1) {
        result.push_back(s);
        return;
    }
    for (int i = start; i < s.length(); i++) {
        if (i != start && s[i] == s[start]) continue; // Skip duplicates
        swap(s[start], s[i]);
        generatePermutations(s, start + 1, result);
        swap(s[start], s[i]); // Backtrack
    }
}

vector<string> permuteUnique(string s) {
    vector<string> result;
    sort(s.begin(), s.end()); // Sort to handle duplicates
    generatePermutations(s, 0, result);
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    vector<string> permutations = permuteUnique(s);
    
    cout << "All unique permutations:" << endl;
    for (const string& perm : permutations) {
        cout << perm << endl;
    }
    
    return 0;
}