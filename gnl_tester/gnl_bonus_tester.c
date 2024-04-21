#include "../get_next_line_bonus.h"

int main(void)
{
	int fd, fd2;
	char *line;

	fd = open("f1.txt", O_RDONLY);
	fd2 = open("f2.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	close(fd);
	close(fd2);

	return (0);
}
