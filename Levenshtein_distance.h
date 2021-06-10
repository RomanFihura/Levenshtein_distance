#pragma once
#include <stdint.h>
#include <string>

class Levenshtein_distance
{
public:
    Levenshtein_distance(std::string A, std::string B)

    {
        if (A == "" || B == "")
        {
            operations = A.size() + B.size();
        }
        else
        {
            str1 = A;
            str2 = B;
        }
    }

    uint32_t Levenshtein_distance_result();

private:
    uint32_t operations = 0;
    std::string str1, str2;

    void insert(uint32_t character);
    void replace(uint32_t iterator);
    void delete_();
};