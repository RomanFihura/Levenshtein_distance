#include "Levenshtein_distance.h"

uint32_t Levenshtein_distance(const std::string &a, const std::string &b)
{
    uint32_t n = a.size() + 1;
    uint32_t m = b.size() + 1;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    uint32_t deletionCost = 1;
    uint32_t insertionCost = 1;

    for (uint32_t i = 0; i < n; i++)
    {
        matrix[i][0] = i;
    }

    for (uint32_t j = 0; j < m; j++)
    {
        matrix[0][j] = j;
    }

    for (uint32_t i = 1; i < n; i++)
    {
        for (uint32_t j = 1; j < m; j++)
        {
            uint32_t substitutionCost = a[i - 1] == b[j - 1] ? 0 : 1;

            matrix[i][j] = std::min(matrix[i - 1][j] + deletionCost,          // delete
                                    std::min(matrix[i][j - 1] + insertionCost,         // insert
                                    matrix[i - 1][j - 1] + substitutionCost)); // replace
        }
    }
    uint32_t temp = matrix[n - 1][m - 1];

    return temp;
}