#include <iostream>
#include <string>
#include <cctype>

std::string trim(const std::string& str)
{
    size_t start = 0;
    while (start < str.length() && isspace(str[start]))
        start++;

    size_t end = str.length();
    while (start < end && isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}

void to_upper_and_print(std::string str)
{
    str = trim(str);
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    std::cout << str;
}

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    for (int i = 1; i < ac; i++)
    {
        to_upper_and_print(av[i]);
        if (i + 1 < ac)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}