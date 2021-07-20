#include "../headers/splitFunc.h"

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    size_t start = 0, end = str.find(delim, start);
    while (end != std::string::npos)
    {
        tokens.push_back(str.substr(start, (end - start)));
        start = end + 1;
        end = str.find(delim, start);
        if (end == std::string::npos){
            end = str.length();
            tokens.push_back(str.substr(start, (end - start)));
            end = std::string::npos;
        }
    }

    return tokens;
}
