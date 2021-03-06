#include "get_next_line.h"

int main(int	ac, char **av)
{
	char *line;
	int	fd;
	int status;
	int i;

	i = 1;
	fd = 0;
	if (ac <= 1)
	{
		status = get_next_line(fd, &line);
		printf("Returned value: %d\t%s\n", status, line);
	}
	if (ac == 2)
	{
		fd = open(av[i], O_RDONLY);
		line = NULL;
		status = 1;
		while(status)
		{
			if (status == -1)
			{
				printf("Error in opening file.\n");
				return (0);
			}
			status = get_next_line(fd, &line);
			printf("Returned value: %d\t%s\n", status, line);
			free ((void *)line);
			line = NULL;
        }
		close (fd);
		i++;
		ac--;
	}
	else
		printf("Argument is not correct\n");
	/* while (1); */ // Add this, then leaks a.out for memory leaks
	return (0); 
}