#ifndef STRING_UTILITIES
#define STRING_UTILITIES

#include <vector>
#include <string>
#include <sstream>

namespace strutils
{
std::vector<std::string> str_split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(s);
    while (std::getline(token_stream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<float> parseVector(const std::string &in, unsigned int size)
{
    float temp;
    std::stringstream strstr;
    std::vector<float> out;
    strstr << in;
    for (unsigned int i = 0; i != size; ++i)
    {
        strstr >> temp;
        out.push_back(temp);
    }

    return out;
}
} // namespace strutils

#endif //STRING_UTILITIES