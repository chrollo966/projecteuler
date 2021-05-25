#include <iostream>
#include <numeric>


using namespace std;

// calculation of two integers' multiples

int sum_1_to_n (int& x) {
    return x * (x + 1) / 2;
}

int calc_sum (int& a, int& b, int& n) {
    // int a, b: two numbers;
    // int n: the number to add
    int num_a = n / a;
    int num_b = n / b;
    int lcm_ab = lcm(a,b);
    int num_lcm = n / lcm_ab;

    int sum_multiples = a * sum_1_to_n (num_a) + b * sum_1_to_n (num_b) - lcm_ab * sum_1_to_n (num_lcm);

    return sum_multiples;
}

int main () {
    int first_number, second_number, num_to_add;
    cout << "Type the first integer: ";
    cin >> first_number;
    cout << "Type the second integer: ";
    cin >> second_number;
    cout << "Type the number to add: ";
    cin >> num_to_add;

    cout << "The sum of their multiples is " << calc_sum(first_number, second_number, num_to_add);
}