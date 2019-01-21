#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>

class Parser
{

  public:
    Parser() : some_string_("") {}

    bool parseLine(const std::string &line);
    std::string toString() const;

  private:
    std::string some_string_;
    std::vector<float> position_;
    std::vector<float> velocity_;
    std::vector<float> covar_;
    std::map<std::string, float> measurements_;

    void parseSomeString(const std::string &in);
    void parseMeasurements(const std::string &in);

    static std::string printVector(const std::vector<float> &vec);
    static std::string printMatrix(const std::vector<float> &mat, unsigned int cols);
    static std::string printMap(const std::map<std::string, float> &map);
};

#endif //PARSER_H