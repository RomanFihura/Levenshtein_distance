#include "Levenshtein_distance.h"

namespace
{
void insert(uint32_t character, std::string &str1)
{
    str1.push_back(character);
}
void replace(uint32_t iterator, std::string &str1, std::string &str2)
{
    str1[iterator] = str2[iterator];
}
void delete_(std::string &str1)
{
    str1.pop_back();
};
} // namespace
uint32_t Levenshtein_distance(const std::string &a, const std::string &b)
{
    uint32_t operations = 0;
    std::string str1 = a;
    std::string str2 = b;
    if ((str1 == "") || (str2 == "")) // if one of str is empty
    {
        int ab = str1.size() - str2.size();
        return abs(ab);
    }
    for (uint32_t i = 0; (str1.size() < str2.size() ? i < str1.size() : i < str2.size()); i++)
    {
        if (str1[i] != str2[i])
        {
            replace(i, str1, str2);
            operations++;
        }
    }
    while (str1.size() < str2.size())
    {
        insert(str2[str1.size()], str1);
        operations++;
    }
    while (str1.size() > str2.size())
    {
        delete_(str1);
        operations++;
    }
    return operations;
}