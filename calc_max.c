#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_calculate(char n)
{
	char	*base;
	int		i;

	base = "0123456789";
	i = 0;
	while (n != base[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *ptr)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '+')
		i++;
	else if (ptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ptr[i] != '\0')
	{
		if (ptr[i] < '0' || ptr[i] > '9')
			return (num * neg);
		num = (num * 10) + ft_calculate(ptr[i]);
		i++;
	}
	return (num * neg);
}

int main(int argc, char **argv)
{
	int		fd;
	int		max;
	int		i;
	int		reader;
	char	r;
	char	num[11];

	if (argc != 2)
	{
		printf("You fucked up.\n");
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	r = '0';
	max = 0;
	//num = malloc((11 * sizeof(char)) + 1);
	while (1)
	{
		i = 0;
		for (int i = 0; i < 11; i++)
			num[i] = 0;
		while (r != '\n')
		{
			reader = read(fd, &r, 1);
			if (!reader)
			{
				close(fd);
				printf("Max: %d\n", max);
				return(0);
			}
			if (r != '\n')
			{
				num[i] = r;
				i++;
			}
		}
		r = '0';
		if (ft_atoi(num) > max)
			max = ft_atoi(num);
	}
}