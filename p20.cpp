#include <iostream>
#include <vector>



int main()
{
    std::vector<int> fact_array = {1};

    for (int next_multiplier = 2; next_multiplier <= 100; next_multiplier++)
    {
        int temp_digit = 0;
        int num_add_to_next_digit = 0;
        bool bool_to_add_next = false;

        for(int i = 0; i < fact_array.size(); i++)
        {
            temp_digit = fact_array[i];
            temp_digit *= next_multiplier;
            if (bool_to_add_next) temp_digit += num_add_to_next_digit;

            if (temp_digit >= 10)
            {
                if (i == fact_array.size() - 1) fact_array.push_back(0);
                num_add_to_next_digit = temp_digit /10;
                fact_array[i] = temp_digit % 10;
                bool_to_add_next = true;
            }
            else
            {
                num_add_to_next_digit = 0;
                fact_array[i] = temp_digit;
                bool_to_add_next = false;
            }
        }
    }

    int sum = 0;
    for (auto &e : fact_array)
    {
        sum += e;
        std::cout << e << " ";
    }

    std::cout << sum;
    return 0;
}