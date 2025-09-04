#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
    } else {
        int top = s.top();
        s.pop();
        insertAtBottom(s, element);
        s.push(top);
    }
}

void reverseStack(stack<int> &s) {
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, top);
    }
}

void printStack(stack<int> s, const string &label) { // pass by value to keep original
    cout << label << " [";
    bool first = true;
    while (!s.empty()) {
        if (!first) cout << ", ";
        cout << s.top();
        s.pop();
        first = false;
    }
    cout << "]\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    stack<int> s;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.push(x);
    }

    // Show BEFORE reversing (top -> bottom)
    printStack(s, "Before reverse (top->bottom):");

    // Reverse and show AFTER (top -> bottom)
    reverseStack(s);
    printStack(s, "After reverse  (top->bottom):");

    return 0;
}

   