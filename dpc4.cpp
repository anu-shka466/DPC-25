#include <iostream>
#include <algorithm>   // for swap
using namespace std;

void mergeArrays(int arr1[], int arr2[], int m, int n) {
    for (int i = 0; i < m; i++) {
        if (arr1[i] > arr2[0]) {
            // Swap
            swap(arr1[i], arr2[0]);

            // Place arr2[0] at correct position to keep arr2 sorted
            int first = arr2[0];
            int k;
            for (k = 1; k < n && arr2[k] < first; k++) {
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first;
        }
    }
}

int main() {
    int m, n;
    
    // Input sizes
    cout << "Enter size of arr1: ";
    cin >> m;
    cout << "Enter size of arr2: ";
    cin >> n;

    int arr1[m], arr2[n];

    // Input arr1
    cout << "Enter elements of arr1 (sorted): ";
    for (int i = 0; i < m; i++) cin >> arr1[i];

    // Input arr2
    cout << "Enter elements of arr2 (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr2[i];

    // Merge
    mergeArrays(arr1, arr2, m, n);

    // Output
    cout << "arr1 = ";
    for (int i = 0; i < m; i++) cout << arr1[i] << " ";
    cout << "\narr2 = ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;
}
