/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> primes;
int N = 2000000;
long sum = 2;

bool is_prime(int n)
{
    bool answer = true;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            answer = false;
            break;
        }
    }

    return answer;
};

int main()
{
    primes.push_back(2);

    for (int i = 3; i < N; i += 2)
    {
        if (is_prime(i) == true)
        {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
    
    return 0;
}