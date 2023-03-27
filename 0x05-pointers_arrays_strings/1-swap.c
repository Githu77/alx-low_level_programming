#include "main.h"
/**
*swap_int - swaps the content of the pointers
*@a: first pointer
*@b: second pointer
*Return : returns nothing
*
*/
void swap_int(int *a, int *b)
{
	int ch = *a;
	*a = *b;
	*b = ch;
}
