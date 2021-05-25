#include <iostream>
#include <vector>

int divisor_sum(int n)
{
    int sum = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            sum += (n / i);
        }
        if (i * i == n)
        {
            sum -= i;
        }
        
    }
    
    return sum;
};

int main()
{
    int last_number = 10000;
    int amicable_sum = 0;
    for (int i = 2; i < last_number; i++)
    {
        int i_divisor_sum = divisor_sum(i);
        int i_divisor_sum_double = divisor_sum(i_divisor_sum); 
        if ((i == i_divisor_sum_double) && (i != i_divisor_sum))
        {
            amicable_sum += i;
            std::cout << i << " ";
    
        }
    }

    std::cout << amicable_sum;

    return 0;

}