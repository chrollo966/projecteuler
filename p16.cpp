
#include <iostream>
#include <vector>

int main()
{
    int times = 1000;
    std::vector<int> power = {1};

    for (int i = 0; i < times; i++)
    {
        int power_next = 0;
        bool bool_next = false;
        for(int j = 0; j < power.size(); j++)
        {
            power[j] *= 2;
            if (bool_next) power[j] += power_next;
            if (power[j] >= 10)
            {
                if (j == power.size() - 1)
                {
                    power.push_back(0);
                }
                power_next = (power[j] / 10);
                power[j] %= 10;
                bool_next = true;
            } else bool_next = false;
        }
    }

    int sum = 0;
    for (auto &e : power)
        sum += e;

    std::cout << sum;
    return 0;
    
}
