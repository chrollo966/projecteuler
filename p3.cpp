#include <iostream>
#include <cmath>

using namespace std;

long fact(long& n) {

    while ((n % 2) == 0) {
        n /= 2;
    }

    for (long i = 3; i < sqrt(n); i += 2) {
        while ((n % i) == 0) {
            n /= i;
        }
    }

    return n;
}

int main() {
    long n;
    cin >> n;
    cout << fact(n);
    return 0;
}