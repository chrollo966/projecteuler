#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>


int main()
{

    int count = 100;
    int digit = 50;
    int first_digit = 10;
    long long answer;

    std::ifstream ifs("./p13.txt");

    if (!ifs)
    {
        std::cerr << "failed to open file" << std::endl;
        std::exit(1);
    }

    std::vector<std::string> numbers;
    std::string buf;
    int i = 0;

    while(std::getline(ifs, buf))
    {
        numbers.push_back(buf);
    }

    long long sum = 0;

    for (int j = 0; j < digit; j++)
    {
        if (j < digit - first_digit){
            for (int i = 0; i < count; i++)
            {
                sum += (numbers[i][digit - 1 - j] - '0'); 
            }
            sum /= 10;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                sum += std::pow(10, j - (digit - first_digit)) * (numbers[i][digit - 1 - j] - '0');
            }

        }
        
    
    }


    std::cout << sum;
    
    return 0;
}