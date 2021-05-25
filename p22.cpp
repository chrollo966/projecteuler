#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

int main()
{
    std::ifstream ifs("./p022_names.txt");
    if (!ifs)
    {
        std::cerr << "failed to open file" << std::endl;
        std::exit(1);
    }

    std::string buf;
    std::string token;
    std::vector<std::string> names;
    while (std::getline(ifs, buf))
    {
        std::istringstream i_stream(buf);
        
        while(std::getline(i_stream, token, ','))
            names.push_back(token);
    }

    std::sort(names.begin(), names.end());

    unsigned int total_score = 0;
    
    for (int i = 0; i < names.size(); i++)
    {
        int value = 0;
        for (auto &char_name : names[i])
        {
            value += char_name - 64;
        }
        value += 60; // ASCII code of ' " ' is 34, so eliminate two ' " '. 

        total_score += value * (i + 1);
    }

    std::cout << total_score;

    return 0;
}