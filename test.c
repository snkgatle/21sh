#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(void)
{
	int fd[2];
	char buff[100];
	
	pipe(fd);
write(fd[1], "Welcome here", 12);
write(fd[1], "CHecking here", 12);
write(fd[1], "CHecking here", 12);
write(fd[1], "CHecking here", 12);
write(fd[1], "CHecking here", 12);
write(fd[1], "CHecking here", 12);
write(fd[1], "CHecking here", 12);
write(fd[1], "\0", 1);
read(fd[0], buff, 100);
printf("%s\n", buff);
}
	
