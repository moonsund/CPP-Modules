#include "Replace.hpp"


std::string ft_replace(
    const std::string& str,
    const std::string& old_value,
    const std::string& new_value
) {
    std::string new_string;
    size_t pos = 0;
    size_t where_found;

    while((where_found = str.find(old_value, pos)) != std::string::npos) {
        new_string = new_string.append(str, pos, where_found - pos);
        new_string.append(new_value);
        pos = where_found += old_value.length();
    }
    new_string.append(str, pos);

    return new_string;
}