#include <iostream>
#include <fstream>

#include "parser.h"

int main(int argc, char const *argv[])
{

    try
    {
        std::ifstream ifs("data/pvt-data.dat");

        if (!ifs.is_open())
            throw std::runtime_error("could not open file");

        std::string line;
        while (std::getline(ifs, line))
        {
            if (line[0] == '#')
                continue;

            std::cout << line << std::endl;
            Parser par;
            if(!par.parseLine(line))
                throw std::runtime_error("parsing did not work");

            std::cout << par.toString();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
