#include "Harl.hpp"
#include <iostream>
#include <sstream>

int main(void) {
    size_t test_passed = 0;
    size_t test_failed = 0;

    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    Harl harl;
    void (Harl::*ptr)(std::string) = &Harl::complain;
    
    for (size_t i = 0; i < 4; i++) {
        std::ostringstream oss;

        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        (harl.*ptr)(levels[i]);

        std::cout.rdbuf(old);

        std::string result = oss.str();
        if (result.find(levels[i]) != std::string::npos) {
            std::cout << "Test for " << levels[i] << " passed" << std::endl;
            test_passed++;
        }
        else {
            std::cout << "Test for " << levels[i] << " failed" << std::endl;
            test_failed++;
        }
    }

    if (test_failed == 0) {
        std::cout << "All tests passed" << std::endl;
    }
    else {
        std::cout << "tests passed: " << test_passed << std::endl;
        std::cout << "tests failed: " << test_failed << std::endl;
    }

    return 0;
}