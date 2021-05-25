#include <iostream>
#include <vector>

// 1901: start from wed

int main()
{   
    int days = 366;
    int sundays = 0;

    std::vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int> months_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int> month_of_year;

    for (int i = 1901; i < 2001; i++)
    {
        // leap year
        if (i % 4 == 0)
        {
            month_of_year = months_leap;
        }
        else month_of_year = months;

        for (auto &e : month_of_year)
        {
            if ((days + 1) % 7 == 0)
            {
                sundays++;
            }
            days += e;
        }

    }

    std::cout << days << std::endl;
    std::cout << sundays << std::endl;

    return 0;

}