#include <stdio.h>

int	check_double(int *stack, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (stack[i] == stack[j])
				return (0);
			printf("%d ", stack[j]);
			j++;
		}
		i++;
	}
	return (1);
}

void test()
{
	int	num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 0 };
	int length = 10;

	if (!check_double(num, length))
		printf("OUT\n");
	if (check_double(num, length))
		printf("OK\n");
}

int main()
{
	test();
}