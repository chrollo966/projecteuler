#include <iostream>
#include <cmath>

int main()
{
    int range = 10000000;
    int total = 0;
    for (int i = 2; i < range; i++)
    {
        int sum = 0;
        int j = i;
        while (j >= 1)
        {
            sum += std::pow((j % 10), 5);
            j /= 10;
        }
        if (sum == i)
        {
            std::cout << sum << " ";
            total += sum;
        }
    }

    std::cout << total;
}