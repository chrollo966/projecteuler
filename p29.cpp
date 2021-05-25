#include <iostream>
#include <set>
#include <cmath>

int main()
{
    std::set<double> powers_set;
    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            double result = std::pow(a, b);
            powers_set.insert(result);
            std::cout << result << " ";
        }
    }
    std::cout << powers_set.size();
}