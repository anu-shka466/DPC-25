#include <iostream>
using namespace std;

long long computeGCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long N, M;
    cout<<"enter two numbers :"<<endl;
    cin >> N >> M;
    long long gcd = computeGCD(N, M);
    long long lcm = (N / gcd) * M;
    cout << lcm << endl;
    return 0;
}