#include <unistd.h>
#include <fcntl.h>
#include "ptdef.h"

void strsingleline(int fd, char *line, size_t lineLen)
{
    ssize_t readcount = read(fd, line, lineLen);
    if (readcount == -1)
        _exit(RDERR);
    if (readcount < lineLen)
        _exit(RDNAV);//Not ideal obviously since read() may return less than the requested amount
    line[lineLen - 1] = '\0'; // null terminate str
}

void strreaduntil(int fd, char *buffer, ssize_t bytestoread)
{
    char *bufferoffset = buffer;
    int bytesread = 0;
    size_t bytesremaining = bytestoread;
    while (bytesread < bytestoread)
    {
        ssize_t readcount = read(fd, bufferoffset, bytesremaining);
        if (readcount < 0)
        {
            return;
        }
        if (readcount == 0)
        {
            return;
        }
        bufferoffset = bufferoffset + readcount;
        bytesread = bytesread + readcount;
        bytesremaining = bytesremaining - readcount;
    }
    buffer[PTBYTES - 1] = '\0'; // null terminate str
}

void readfullperiodictable(char *fullfilebuffer)
{
    int fd = open("periodictable", O_RDONLY);
    strreaduntil(fd, fullfilebuffer, PTBYTES);
}
