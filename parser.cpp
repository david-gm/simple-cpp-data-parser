#include "parser.h"

#include <iostream>
#include "string_utilities.h"

bool Parser::parseLine(const std::string &line)
{
    std::vector<std::string> split_line = strutils::str_split(line, ',');

    parseSomeString(split_line.at(0));
    position_ = strutils::parseVector(split_line.at(1), 3);
    velocity_ = strutils::parseVector(split_line.at(2), 3);
    covar_ = strutils::parseVector(split_line.at(3), 9);
    parseMeasurements(split_line.at(4));

    return true;
}

std::string Parser::toString() const
{
    std::stringstream strstr;
    strstr << "some string:\t|" << some_string_ << "|\n";
    strstr << "position:\t" << Parser::printVector(position_) << "\n";
    strstr << "velocity:\t" << Parser::printVector(velocity_) << "\n";
    strstr << "co-variance:\t" << Parser::printMatrix(covar_, 3) << "\n";
    strstr << "measurements(" << measurements_.size() << "):\n"
           << Parser::printMap(measurements_) << "\n";
    return strstr.str();
}

void Parser::parseSomeString(const std::string &in)
{
    std::stringstream strstr;
    strstr << in;
    strstr >> some_string_;
}

void Parser::parseMeasurements(const std::string &in)
{
    std::stringstream strstr;
    strstr << in;

    int num_measurements;
    strstr >> num_measurements;

    std::string key;
    float val = 0.0;
    for (unsigned int i = 0; i != num_measurements; ++i)
    {
        strstr >> key >> val;
        measurements_.insert(std::make_pair(key, val));
    }
}

std::string Parser::printVector(const std::vector<float> &vec)
{
    std::string out("|");
    for (unsigned int i = 0; i != vec.size(); ++i)
    {
        out += std::to_string(vec.at(i));
        if (i != vec.size() - 1)
            out += " ";
    }
    out += "|";
    return out;
}

std::string Parser::printMatrix(const std::vector<float> &mat, unsigned int cols)
{
    std::string out("|");
    for (unsigned int i = 0; i != mat.size(); ++i)
    {
        out += std::to_string(mat.at(i));
        if ((i + 1) % cols == 0 && i != mat.size() - 1)
            out += "|\n\t\t|";
        if (i != mat.size() - 1)
            out += " ";
    }
    out += "|";
    return out;
}

std::string Parser::printMap(const std::map<std::string, float> &map)
{
    std::string out;
    for (auto &pair : map)
        out += "\t\t" + pair.first + ":\t" + std::to_string(pair.second) + "\n";
    return out;
}