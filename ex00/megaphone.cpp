#include<iostream>
#include<stdio.h>

int main (int ac,char **av)
{
	int i;
	i = 1;
	if (ac == 1)
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (ac > 1)
	{
		while (i <  ac)
		{
			int j = 0;
			while (av[i][j])
			{
				//std :: cout << av[i][j];
				//std :: cout << "\n";
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
				{
					av[i][j] -= 32;
					std :: cout << av[i][j];
				}
				else
					std :: cout << av[i][j];
				j++;
			}
			i++;
		}
	}
	return 0;
}
