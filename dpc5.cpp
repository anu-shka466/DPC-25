#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int leaders[n];   // to store leader elements
    int count = 0;    // number of leaders found

    int max_from_right = arr[n-1];
    leaders[count++] = max_from_right;  // last element is always a leader

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            leaders[count++] = arr[i];
            max_from_right = arr[i];
        }
    }

    // print leaders in correct order (reverse of how we stored)
    cout << "Leaders: ";
    for (int i = count-1; i >= 0; i--) {
        cout << leaders[i] << " ";
    }
    cout << endl;

    return 0;
}
