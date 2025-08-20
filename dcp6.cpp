
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findZeroSumSubarrays(vector<int>& arr) {
    vector<pair<int,int>> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                result.push_back({i, j});
            }
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int,int>> ans = findZeroSumSubarrays(arr);

    cout << "Zero sum subarrays (start, end):\n";
    for (auto &p : ans) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}