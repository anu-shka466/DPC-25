#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    vector<string> strs;
    string input;
    
    cout << "Enter strings separated by spaces (e.g., eat tea tan ate nat bat): ";
    getline(cin, input);
    
    // Parse input string into vector of strings
    istringstream iss(input);
    string word;
    while (iss >> word) {
        strs.push_back(word);
    }
    
    // Handle empty input case
    if (strs.empty()) {
        cout << "[[]]" << endl;
        return 0;
    }
    
    vector<vector<string>> result = groupAnagrams(strs);
    
    // Format and print output
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}



