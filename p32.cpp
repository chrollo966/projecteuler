#include <iostream>
#include <string>
#include <vector>

bool is_in_vector(int n, std::vector<int> vec)
{
    bool answer = false;

    for (auto& e: vec)
    {
        if (e == n){
            answer = true;
            break;
        }
    }

    return answer;
}

bool is_pandigit(int n)
{
    bool answer = true;
    std::vector<int> pandigit = {};
    while(n >= 1)
    {
        if(is_in_vector(n % 10, pandigit))
        {
            answer = false;
            break;
        }
    
        pandigit.push_back(n % 10);
        n /= 10;
    }

    return answer;
}

bool check_zero_contained(std::string str)
{
    bool answer = false;
    for (auto &e : str)
    {
        if (e == '0') 
        {
            answer = true;
            break;
        }
    }
    return answer;
}

bool reprentable_pandigital_product(int n)
{
    bool answer = false;
    if (!is_pandigit(n))
    {
        answer = false;
        return answer;
    }

    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            if (!is_pandigit(i) || !is_pandigit(n / i))
            {
                answer = false;
                continue;
            }

            std::string concat = std::to_string(i) + std::to_string(n / i) + std::to_string(n);

            // break if 0 is contained
            if (check_zero_contained(concat) || concat.size() != 9)
            {
                answer = false;
                continue;
            }

            int concat_number = std::stoi(concat);

            if(is_pandigit(concat_number))
            {
                std::cout << i << " " << n / i << " " << n << std::endl;; //debug
                answer = true;
                break;
            };
        }

    }
    return answer;
}

int main()
{
    int sum = 0;
    std::vector<int> pandigit_vector;
    for(int i = 1000; i < 10000; i++)
    {
        if (reprentable_pandigital_product(i) && !is_in_vector(i, pandigit_vector))
        {
            pandigit_vector.push_back(i);
            sum += i;
        };

    }
    std::cout << sum;
    return 0;
}