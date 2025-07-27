#include <string.h>
#include <unistd.h>
#include "stdint.h"
#include "ptdef.h"
#include "Element.h"

struct Element hydrogen = { .name = "hydrogen", .abbrev = "H", .atnum = 1 };

int8_t ELS_LN = 1;//There are currently only 118 known elements and int8_t allows 255.
struct Element els[1] = { { .name = "hydrogen", .abbrev = "H", .atnum = 1 } };//Using ELS_LN here instead of numeric literal causes file scope error. Why?

int ptsearch(char *searchterm, char *result, size_t maxresultsize)
{
    if (maxresultsize < 100) return 1;

    for (int8_t i = 0; i < ELS_LN; i++)
    {
        if (strncmp(searchterm, els[i].abbrev, 2) == 0)
        {
            strcpy(result, "MATCH FOUND");
            return 0;
        }
    }

    return 101;
}

/* Old Search */
//A match is found. The table must be searched and all desired information must be written to the result.
//Buffering the periodictable file on every search might be slow?
//Instead of opening/seeking/reading from a file map the file into virtul memory first (mmap), then read the mapped area instead of the file.
//int fd = open("periodictable", O_RDONLY);
//int offset = lseek(fd, 0, SEEK_SET);
//if (offset != 0) return 102;
//offset = lseek(fd, HYDROGEN_INDEX, SEEK_CUR);
//if (offset != HYDROGEN_INDEX) return 103;
//char periodicline[100];
//read(fd, periodicline, HYDROGEN);
//strcpy(result, periodicline);
//return 0;
