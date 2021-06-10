#include "Levenshtein_distance.h"

uint32_t Levenshtein_distance::Levenshtein_distance_result()
{
    if (operations) // if one of str is empty
    {
        return operations;
    }
    for (uint32_t i = 0; (str1.size() < str2.size() ? i < str1.size() : i < str2.size()); i++)
    {

        if (str1[i] != str2[i])
        {
            replace(i);
        }
    }
    while (str1.size() < str2.size())
    {
        insert(str2[str1.size()]);
    }
    while (str1.size() > str2.size())
    {
        delete_();
    }
    return operations;
}
void Levenshtein_distance::insert(uint32_t character)
{
    str1.push_back(character);
    operations++;
}
void Levenshtein_distance::replace(uint32_t iterator)
{
    str1[iterator] = str2[iterator];
    operations++;
}
void Levenshtein_distance::delete_()
{
    str1.pop_back();
    operations++;
};