#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primeFactorization(int N) {
    vector<int> factors;
    // Factor out all 2s
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
    // Now N must be odd, so we start from 3 and go up to sqrt(N)
    for (int i = 3; i <= sqrt(N); i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    // If N is still greater than 1, it is a prime number
    if (N > 1) {
        factors.push_back(N);
    }
    return factors;
}

int main() {
    int N;
    cout<<"enter the number:"<<endl;
    cin >> N;
    vector<int> result = primeFactorization(N);
    // Output the result
    for (size_t i = 0; i < result.size(); i++) {
        if (i != 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}