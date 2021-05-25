#include <iostream>
#include <vector>

int main()
{
    int target = 200;
    std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<int> ways(target + 1);
    ways.at(0) = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= target; j++)
        {
            ways[j] += ways[j - coins[i]];
            std::cout << ways[j] << " ";
        }
        std::cout << std::endl;
    }
    
}