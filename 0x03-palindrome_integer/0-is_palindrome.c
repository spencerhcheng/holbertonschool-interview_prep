#include "palindrome.h"

int is_palindrome(unsigned long n)
{
	int divisor;
	int __length;

	__length = length_n(n);

	divisor = power_recurse(10, __length - 1);
	return (pal_check(divisor, n)); 

	return (0);
}

int power_recurse(int x, int power)
{
	if (power < 0)
	{
		return (-1);
	}
	else if (power == 0)
	{
		return (1);
	}
	return (x * power_recurse(x, power - 1));
}


int pal_check(int divisor, unsigned int n)
{
	int leading;
	int trailing;


	if (length_n(n) == 1)
		return (1);

	while (length_n(n) != 1)
	{
		leading = n / divisor;
		trailing = n % 10;
	if (leading != trailing)
		return (0);
	n = (n % divisor) / 10;
	divisor = divisor / 100;
	if (n == 0)
		return (1);
	return pal_check(divisor, n);
	}
	return (1);
}

int length_n(unsigned long n)
{
    int count = 0;

    while (n > 0)
    {
        n = n / 10;
        count ++;
    }
    return (count);
}
