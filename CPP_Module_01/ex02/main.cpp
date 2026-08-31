#include <string>
#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string str1 = "new";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // std::cout << &str << std::endl;
    // std::cout << stringPTR << std::endl;
    // std::cout << &stringREF << std::endl;

    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    

    stringREF = str1;
    std::cout << &str << std::endl;
    std::cout << &str1 << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    std::cout << &str << std::endl;
    std::cout << &str1 << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
}
