#include <iostream>
#include <string>

int fact (int n)
{
    int answer = 1;
    if (n == 0)
    {
        answer = 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            answer *= i;
    }

    return answer;
};

int main()
{
    std::string number = "0123456789";
    const int digits = number.size();
    const int millionth = 1000000;
    int toggle = 0;
    int shift = 0;
    int factorial;
    int factorized_digit = 0; // first digit (9)
    int nth = 0;

    while(nth != millionth)
    {
        factorial = fact(factorized_digit) + nth;

        if (factorial < millionth)
        {
            factorized_digit++;
        }
        else
        {
            if (toggle == factorized_digit)
            {
                shift++;
            }
            else
            {
                shift = 0;
            }
            nth += fact(factorized_digit - 1);
            std::swap(number[digits - factorized_digit], number[digits - factorized_digit + 1 + shift]);
            std::cout << factorized_digit << " " << nth << " " << number << std::endl;
            toggle = factorized_digit;
            factorized_digit = 0;
            
        }
    }

    return 0;
}