#include <iostream>
#include <numeric>
using namespace std;

int lcm_n (int n) {
    int lcm_temp = 2;
    for (int i = 1; i < n + 1; i++) {
        lcm_temp = lcm (i, lcm_temp);
    }
    return lcm_temp;
}

int main() {
    cout << lcm_n(20);
}