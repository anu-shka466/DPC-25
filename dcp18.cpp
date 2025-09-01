#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cout<<"enter the number:"<<endl;
    cin >> N;
    
    if (N == 1) {
        cout << 1;
        return 0;
    }
    
    int count = 0;
    int i = 1;
    while (i * i <= N) {
        if (N % i == 0) {
            if (i * i == N) {
                count++;
            } else {
                count += 2;
            }
        }
        i++;
    }
    cout<<"total number of divisors are :";
    cout << count;
    return 0;
}