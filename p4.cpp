#include <iostream>
#include <vector>
#include <deque>

using namespace std;


bool is_palindrome(int n) {

    deque<int> digit_numbers;
    bool pal;
    
    if (n < 0) {
        n = -n;
    }

    while (n >= 1) {
        digit_numbers.push_back(n % 10);
        n /= 10;
    }
    

    for (long i = 0; i <= (digit_numbers.size() / 2); i++) {
        if (digit_numbers[i] != digit_numbers[digit_numbers.size() - 1 - i]) {
            pal = false;
            break;
        } else {
            pal = true;
        }
    }

    return pal;

}

int main() {
    long long pal_factor_1, pal_factor_2, pal_product, pal_answer;
    bool finished = false;

    for (int i = 999999; i > 100; i--) {
        for (int j = 999999; j > 100; j--) {
            for (int k = 0; k < i - j + 1; k++) {
                pal_product = (i - k) * (j + k);
                if (is_palindrome(pal_product) == true) {
                    pal_factor_1 = i - k;
                    pal_factor_2 = j + k;
                    pal_answer = pal_product;
                    finished = true;
                    break;
                }

            }
            if (finished == true)
                break;
        }
        if (finished == true)
            break;
    }

    cout << pal_factor_1 << " * " << pal_factor_2 << " = " << pal_answer;
}