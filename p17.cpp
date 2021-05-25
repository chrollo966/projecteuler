#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> num_words = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
    std::vector<std::string> num_words_teen_joint = {"thir", "four", "fif", "six", "seven",  "eigh", "nine"};
    std::vector<std::string> num_words_ty_joint = {"twen", "thir", "for", "fif", "six", "seven", "eigh", "nine"};
    std::vector<std::string> num_words_suffix = {"teen", "ty", "hundred", "thousand"};


    int sum = 0;
    int ten_digit;
    int one_digit;
    int hundred_digit;
    int ten_one_digit;
    std::string new_word;
    std::string and_word;
    for (int i = 1; i < 1000; i++)
    {
        if (i < 13)
        {
            sum += num_words[i].length();
        }
        else if (12 < i && i < 20)
        {
            new_word = num_words_teen_joint[i - 13] + num_words_suffix[0];
            num_words.push_back(new_word);
            sum += new_word.length();

        }
        else if (19 < i && i < 100)
        {
            ten_digit = i / 10;
            one_digit = i % 10;
            new_word = num_words_ty_joint[ten_digit - 2] + num_words_suffix[1] + num_words[one_digit];
            num_words.push_back(new_word);
            sum += new_word.length();
        }
        else
        {
            hundred_digit = i / 100;
            ten_one_digit = i % 100;
            and_word = i % 100 == 0 ? "" : "and";
            new_word = num_words[hundred_digit] + num_words_suffix[2] + and_word + num_words[ten_one_digit];
            num_words.push_back(new_word);
            sum += new_word.length();
        }
    }


    
    sum += (num_words[1] + num_words_suffix[3]).length();
    std::cout << sum;

    return 0;
}