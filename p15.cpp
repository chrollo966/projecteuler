#include <iostream>
#include <cmath>

unsigned long long comb(unsigned long long n, unsigned long long k)
{
    if (k > (n / 2))
        k = n - k;

    unsigned long long r = 1;
    for (int i = 1; i <= k; i++)
    {
        r *= n--;
        r /= i;
    }

    return r;
}

int main()
{
    std::cout << comb(40, 20);
    return 0;
}