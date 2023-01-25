#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	last_2(char *num)	// if the last 2 are in descending order (1 2 3 5 4)
{						// return 1
	if (num[3] > num[4])
		return (1);
	return (0);
}

int	last_3(char *num)	// if the last 3 are in descending order (1 2 5 4 3)
{						// return 1
	if (last_2(num) && num[2] > num[3])
		return (1);
	return (0);
}

int	last_4(char *num)	// if the last 4 are in descending order (1 5 4 3 2)
{						// return 1
	if (last_3(num) && num[1] > num[2])
		return (1);
	return (0);
}

int	backwards_check(char *num)
{
	if (num[0] == '5' && num[1] == '4' && num[2] == '3' && num[3] == '2' && num[4] == '1')
		return(0);
	return(1);
}

int main()
{
	char	num[5] = {'1', '2', '3', '4', '5'};
	FILE	*fd;
	int		flip;
	char	sel;
	char	file[13] = "tests/001.txt";

	fd = fopen(file, "w");
	while (backwards_check(num))
	{
		flip = 0;
		fprintf(fd, "%c %c %c %c %c\n", num[0], num[1], num[2], num[3], num[4]);
		fclose(fd);
		if (file[8] == '9')
		{
			if (file[7] == '9')
			{
				file[6] = '1';
				file[7] = '0';
				file[8] = '0';
			}
			else
			file[7]++;
			file[8] = '0';
		}
		else
			file[8]++;
		fd = fopen(file, "w");
		if (last_4(num))
		{
			num[0]++;
			num[1] = '1';
			num[2] = '2';
			num[3] = '3';
			num[4] = '4';
			for (int i = 1; i < 5; i++)
			{
				if (num[i] == num[0])
					flip++;
				if (flip)
					num[i]++;
			}
		}
		else if (last_3(num))
		{
			num[1]++;
			if (num[1] == num[0])
				num[1]++;
			sel = '1';
			for (int i = 2; i < 5; i++)
			{
				while (sel == num[0] || sel == num[1])
					sel++;
				num[i] = sel;
				sel++;
			}
		}
		else if (last_2(num))
		{
			num[2]++;
			if (num[2] == num[0] || num[2] == num[1])
				num[2]++;
			sel = '1';
			for (int i = 3; i < 5; i++)
			{
				while (sel == num[0] || sel == num[1] || sel == num[2])
					sel++;
				num[i] = sel;
				sel++;
			}
		}
		else
		{
			sel = num[4];
			num[4] = num[3];
			num[3] = sel;
		}
	}
}