// Longest Collatz sequence

#include <iostream>
#include <vector>


int main()
{
    const int range = 1000000;
    int start_num = 0;
    int seq_length = 0;
    long seq;

    int * cache = new int[range + 1];
    for (int i = 0; i < range; i++)
    {
        cache[i] = -1;
    }
    cache[1] = 1;


    for (int i = 2; i < range; i++)
    {
        seq = i;
        int count = 0;
        while(seq != 1 && seq >= i)
        {
            if (seq % 2 == 0)
            {
                seq /= 2;
                count++;
            }
            else
            {
                seq = 3 * seq + 1;
                count++;
            }
        }

        cache[i] = count + cache[seq];

        if (cache[i] > seq_length)
        {
            seq_length = cache[i];
            start_num = i;
        }
    }

    std::cout << "starting number: " << start_num << std::endl;
    std::cout << "length: " << seq_length << std::endl;
}