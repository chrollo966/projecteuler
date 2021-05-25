#include <iostream>
#include <vector>

int main()
{
    std::vector<int> fib_1 = {1};
    std::vector<int> fib_2 = {1};
    std::vector<int> fib_sum = {};

    int index = 2;
    int fib_digit_sum;
    int toggle;

    while(fib_2.size() < 1000)
    {
        toggle = 0;
        if (fib_1.size() < fib_2.size()) fib_1.push_back(0);
        for (int i = 0; i < fib_2.size(); i++)
        {
            fib_digit_sum = fib_1[i] + fib_2[i] + toggle;
            toggle = fib_digit_sum / 10;
            fib_sum.push_back(fib_digit_sum % 10);
            if (i == fib_2.size() - 1 && toggle > 0)
            {
                fib_sum.push_back(toggle);
            }

        }

        fib_1 = fib_2;
        fib_2 = fib_sum;
        fib_sum = {};
        index++;
    }

    std::cout << index;
    

    return 0;
}