#include "main.h"
/**
*is_prime_number - checks if int is prime
*@n: int in question
*Return: 0 if prime
*
*
*
*/
int is_prime_number(int n)
{
	int i = n / 2;

	if (n <= 1)
	{
		return (0);
	}
	else
	{
		return (is_pnum(n, i));
	}
}
/**
*is_pnum - checks for prime
*@n: int in question
*@i: beginning of int
*Return: 1 if prime
*
*
*/
int is_pnum(int n, int i)
{
	if (i <= 1)
	{
		return (1);
	}
	else if (n % i == 0)
	{
		return (0);
	}
	else
	{
		return (is_pnum(n, i - 1));
	}
}
