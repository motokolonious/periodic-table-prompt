#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define HEADER 55 /* Line lengths include separators, but are later replaced with null terminators */
#define HYDROGEN 30
#define HELIUM 27

#define PTBYTES 112 /* Full byte count of entire periodictable file */

#define RDERR 1 /* Read error */
#define RDNAV 2 /* Read some data not available */

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

int main(int argc, char *argv[])
{
    char inputarray[100];
    while(strncmp(inputarray, "exit", 4) != 0)
    {
        write(STDOUT_FILENO, "conschem> ", 10);
        ssize_t readcount = read(STDIN_FILENO, inputarray, 100); //todo: use fn to read remaining bytes
        if (strncmp(inputarray, "print", 5) == 0)
        {
            char fullperiodictable[PTBYTES];
            readfullperiodictable(fullperiodictable);
            write(STDOUT_FILENO, fullperiodictable, PTBYTES);
            write(STDOUT_FILENO, "\n", 1);
        }
    }

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
