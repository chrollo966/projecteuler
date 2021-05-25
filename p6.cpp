#include <iostream>

using namespace std;

int sum_square (int n) {
    int temp = 0;
    for (int i = 1; i < n + 1; i++) {
        temp += i;
    }
    return temp * temp;
}

int square_sum (int n) {
    int temp = 0;
    for (int i = 1; i < n + 1; i++) {
        temp += i * i; 
    }
    return temp;
}

int main() {
    cout << sum_square(100) - square_sum(100);
}