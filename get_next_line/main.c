#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *str = 0;
	int fd = open("test2.txt", O_RDONLY);
	int fd2 = open("test3.txt", O_RDONLY);
	int fd3 = open("test4.txt", O_RDONLY);
	int i;

	while ((i = get_next_line(fd, &str)))
	{
		
		printf("|FD1(%i) - %s|\n", i, str);
		free(str);
		i = get_next_line(fd2, &str);
		printf("|FD2(%i) - %s|\n", i, str);
		free(str);
		i = get_next_line(fd3, &str);
		printf("|FD3(%i) - %s|\n", i, str);
		free(str);
	}
	printf("|FD1(%i) - %s|\n", i, str);
	free(str);
	i = get_next_line(fd2, &str);
	printf("|FD2(%i) - %s|\n", i, str);
	free(str);
	i = get_next_line(fd3, &str);
	printf("|FD3(%i) - %s|\n", i, str);
	free(str);

	close(fd);
	return(0);
}