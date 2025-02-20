#include <stdio.h>

int	main()
{
	double big = 1e6;
	printf("big is %e \n 1e12 is %e \n Divided by 1000, it is %e \n", big, 1e12, 1e12 / 1000);
	return 0;
}