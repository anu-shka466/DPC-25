#include <iostream>
#include <stack>
using namespace std;

// Function to insert element in sorted order
void sortedInsert(stack<int>& st, int x) {
    // If stack is empty or top element <= x, push x
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    // Otherwise, pop top and recur
    int temp = st.top();
    st.pop();
    sortedInsert(st, x);

    // Push back the stored element
    st.push(temp);
}

// Function to sort the stack recursively
void sortStack(stack<int>& st) {
    if (st.empty()) return;

    // Pop the top element
    int x = st.top();
    st.pop();

    // Sort the remaining stack
    sortStack(st);

    // Insert the popped element back in sorted order
    sortedInsert(st, x);
}

// Function to print stack (top to bottom)
void printStack(stack<int> st) {
    if (st.empty()) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    bool first = true;
    while (!st.empty()) {
        if (!first) cout << ", ";
        cout << st.top();
        st.pop();
        first = false;
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;
    int n;

    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter elements (top to bottom): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    printStack(st);

    return 0;
}
