#include <fcntl.h>
#include <string.h>
#include "ptsearch.h"
#include "ptdef.h"
#include "ptreadwrite.h"

int main(int argc, char *argv[])
{
    char inputarray[100];
    while(strncmp(inputarray, "exit", 4) != 0)
    {
        write(STDOUT_FILENO, "conschem> ", 10);
        ssize_t readcount = read(STDIN_FILENO, inputarray, 100); //todo: use fn to read remaining bytes

        //print some periodic table summarization text
        if (strncmp(inputarray, "print", 5) == 0)
        {
            char fullperiodictable[PTBYTES];
            readfullperiodictable(fullperiodictable);
            write(STDOUT_FILENO, fullperiodictable, PTBYTES);
            write(STDOUT_FILENO, "\n", 1);
        }

        //inputs that aren't other commands should be evaluated as possible searches
        if (strncmp(inputarray, "exit", 4) != 0)
        {
            inputarray[1] = '\0';//For now null terminate for 1-letter searches.
            char searchresult[100];
            int searchfailure = ptsearch(inputarray, searchresult, 100);
            if (searchfailure == 0)
            {
                write(STDOUT_FILENO, searchresult, strlen(searchresult));
                write(STDOUT_FILENO, "\n", 1);
            }
            else write(STDOUT_FILENO, "No search results found!\n", 26);
        }
    }
    return 0;
    /* File is formatted as comma delimited with LF line separators */
    /*if (argc > 1)
    {
        char fullperiodictable[PTBYTES];
        readfullperiodictable(fullperiodictable);
        printf("%s\n", fullperiodictable);
    }
    else
    {
        int fd = open("periodictable", O_RDONLY);
        char header[HEADER];
        strsingleline(fd, header, HEADER);
        printf("%s\n", header);

        char hydrogen[HYDROGEN];
        strsingleline(fd, hydrogen, HYDROGEN);
        printf("%s\n", hydrogen);

        char helium[HELIUM];
        strsingleline(fd, helium, HELIUM);
        printf("%s\n", helium);
        close(fd);
    }*/
}
