#include <iostream>
#include <numeric>

using namespace std;

//sum of even fibonacci sequence < 4000000

int sef (int& n) {
    int ef_n_2 = 2;
    int ef_n_1 = 8;
    int ef_n;
    int sum = 2 + 8;

    if (n < 2)
        return 0;
    
    while (ef_n < n) {

        ef_n = 4 * ef_n_1 + ef_n_2;

        if (ef_n > n)
            return sum;

        sum += ef_n;
        ef_n_2 = ef_n_1;
        ef_n_1 = ef_n;

    }

    return sum;

};

int main() {
    int n;
    cin >> n;
    cout << sef(n);
    return 0;
}