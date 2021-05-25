#include <iostream>
#include <vector>

int main()
{
    const int range = 1000;
    int rec_length = 0;
    int longest_rec_denom = 0;

    for (int denom = range; denom > 1; --denom)
    {
        if (rec_length >= denom) break;

        std::vector<int> rem_array(denom);
        int num = 1;
        int position = 0;
        while(rem_array[num] == 0 && num != 0)
        {
            rem_array[num] = position;
            num *= 10;
            num %= denom;
            position++;
        }

        if (position - rem_array[num] > rec_length)
        {
            rec_length = position - rem_array[num];
            longest_rec_denom = denom;
        }        
    }

    std::cout << rec_length << " " << longest_rec_denom << std::endl;

}