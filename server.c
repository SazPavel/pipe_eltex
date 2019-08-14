#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    unlink("./tempfifo");
    if(mkfifo("./tempfifo", S_IRUSR | S_IWUSR) < 0)
    {
        perror("mkfifo");
        exit(-1);
    }
    fd = open("./tempfifo", O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        exit(-1);
    }
    write(fd, "Hello\n", 6);

    exit(0);
}