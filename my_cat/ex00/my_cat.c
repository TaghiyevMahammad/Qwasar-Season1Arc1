#include <fcntl.h>
#include <unistd.h>

char buf[1024];

int main (int ac, char **av) 
{
    int fd, r, i = 1;
    while (i < ac)
    {
        fd = open(av[i], O_RDONLY);
        if (fd >= 0)
        {
            while ((r = read(fd,buf,1024)) > 0)
                write(1,buf,r);
            close(fd);
        }
        i++;
    }
    return 0;
}