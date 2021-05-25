#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

int main()
{

    // download text file
    std::ifstream ifs("./p18.txt");

    if (!ifs)
    {
        std::cerr << "failed to open file" << std::endl;
        std::exit(1);
    }

    int text_lines = 15;

    int line = 0;

    std::string buf;
    std::vector<std::vector<int> > numbers(text_lines, std::vector<int>(0));
    while (std::getline(ifs, buf))
    {
        std::string token;
        std::istringstream stream(buf);
        while (std::getline(stream, token, ' '))
        {
            int temp = std::stoi(token);
            numbers.at(line).push_back(temp);
        }
        line++;
    }

    
    for (int i = 13; i >= 0; i--)
    {
        for (int j = 0; j < numbers.at(i).size(); j++)
        {
            int upper_num = numbers.at(i).at(j);
            int sum_1 = upper_num + numbers.at(i + 1).at(j);
            int sum_2 = upper_num + numbers.at(i + 1).at(j + 1);
            numbers.at(i).at(j) = std::max(sum_1, sum_2);
        }

    }

    std::cout << numbers.at(0).at(0);


    return 0;

}