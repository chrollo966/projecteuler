#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n)
{
    if (n % 2 == 0) return false;
    if (n < 0) n = std::abs(n);
    bool answer = true;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            answer = false;
            break;
        }
    }
    return answer;
}

int main()
{
    int max_consec = 0; 
    int first_coeff = 0;
    int second_coeff = 0;

    const int range = 1000;

    for (int a = -range + 1; a < range; a++)
    {
        for (int b = -range; b <= range; b++)
        {
            int n = 0;
            while (is_prime(n * (n + a) + b))
            {
                n++;
            }
            
            if (max_consec < n)
            {
                max_consec = n;
                first_coeff = a;
                second_coeff = b;
            }
        }
    }
    std::cout << "n^2 + " << first_coeff << "n + " << second_coeff << " generates " << max_consec << " consective primes." << std::endl;
    std::cout << first_coeff << " * " << second_coeff << " = " << first_coeff * second_coeff << std::endl;

    return 0;
}