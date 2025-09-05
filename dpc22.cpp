#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findFirstElementWithKOccurrences(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : arr) {
        freq[num]++;
    }

    // Traverse array in original order
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1; // If no element found
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int result = findFirstElementWithKOccurrences(arr, k);
    cout << "Output: " << result << endl;

    return 0;
}
