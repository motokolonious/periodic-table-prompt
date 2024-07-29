#include <string.h>

char ElementAbbreviations[2][2] = { "H", "He" };

int ptsearch(char *searchterm, char *result, size_t maxresultsize)
{
    if (maxresultsize < 100) return 1;

    for (int i = 0; i < 2; i++)
    {
        if (strncmp(searchterm, ElementAbbreviations[i], 2) == 0)
        {
            //A match is found. The table must be searched and all desired information must be written to the result.
            strcpy(result, "testing ALL the things out\n");
            return 0;
        }
    }

    return 101;
}
