#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string expression;
    cout<<"enter the postfix expression:"<<endl;
    getline(cin, expression);
    stack<int>st;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(a - b);
            } else if (token == "*") {
                st.push(a * b);
            } else if (token == "/") {
                st.push(a / b);
            }
        } else {
            st.push(stoi(token));
        }
    }
    
    cout << st.top() << endl;
    
    return 0;
}