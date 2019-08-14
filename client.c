#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf[10];
    
    fd = open("./tempfifo", O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        exit(-1);
    }
    read(fd, buf, 6);
    printf("%s", buf);
    unlink("./tempfifo");
    exit(0);
}