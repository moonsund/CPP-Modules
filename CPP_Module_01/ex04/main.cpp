#include "Replace.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

std::string ft_replace(
    const std::string& str,
    const std::string& old_value,
    const std::string& new_value
);

int main(int ac, char** av) {
    if (ac != 4) {
        std::cerr << "Error. Usage: ./ex04 <filename> <old_value> <new_value>\n";
        return 1;
    }
        
    if (std::string(av[2]).empty()) {
        std::cerr << "Error. <old_value> can not be empty\n";
        return 1;
    }
    
    std::string input_file_name = std::string(av[1]);
    std::string output_file_name = std::string(av[1]) + ".replace";

    std::ifstream infile(input_file_name);
    if (!infile.is_open()) {
        std::cerr << "could not open " << input_file_name << " file" << std::endl;
        return 1;
    }

    std::ofstream outfile(output_file_name);
    if (!outfile.is_open()) {
        std::cerr << "could not open " << output_file_name << " file" << std::endl;
        return 1;
    }

    std::string old_value = av[2];
    std::string new_value = av[3];
    std::string text(
        (std::istreambuf_iterator<char>(infile)),
        std::istreambuf_iterator<char>()
    );

    outfile << ft_replace(text, old_value, new_value);

    return 0;
}