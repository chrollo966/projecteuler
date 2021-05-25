#include <iostream>
#include <vector>
#include <chrono>

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
    int index = 0;
    const int upper_limit = 28123;
    std::vector<int> abundants;
    int non_abundant_sum = 23 * 24 / 2 ;

    // time measurement
    std::chrono::system_clock::time_point start, end;
    std::time_t time_stamp;

    // start measurement
    start = std::chrono::system_clock::now();

    for (int i = 1; i <= upper_limit; i++)
    {
        if (divisor_sum(i) > i)
        {
            abundants.push_back(i);
        }

        if (i >= 24)
        {
            int low = 0;
            int high = abundants.size() - 1;
            int candidate = abundants[low] + abundants[high];
            
            while (candidate != i && low <= high)
            {
                if (candidate > i)
                {
                    high--;
                }
                else 
                {
                    low++;
                }
                candidate = abundants[low] + abundants[high];

            }

            if (candidate != i)
            {
                non_abundant_sum += i;
            }
        }
    }

    // stop measurement
    end = std::chrono::system_clock::now();

    // process time
    auto time = end - start;
    
    // time stamp of start time
    time_stamp = std::chrono::system_clock::to_time_t(start);

    std::cout << std::ctime(&time_stamp);

    // to milisec
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

    std::cout << msec << " msec" << std::endl;


    std::cout << non_abundant_sum ;

    return 0;
}
