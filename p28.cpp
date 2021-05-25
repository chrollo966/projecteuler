#include <iostream>

auto diagonal_sum (int n)
{
    n = (n - 1) / 2;
    return (16 * (n * n * n) + 30 * (n * n) + 26 * n) / 3 + 1;
};
int main()
{
    int n = 1001;
    std::cout << diagonal_sum(n);
     
}