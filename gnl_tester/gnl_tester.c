#include "../get_next_line.h"



int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error\n");
			return (1);
		}
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		close(fd);
	}
	else if (argc == 1)
	{
		line = get_next_line(0);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(0);
		}
		free(line);
	}
	else
	{
		printf("Error\n");
		return (1);
	}

}

