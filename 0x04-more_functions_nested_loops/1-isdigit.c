#include "main.h"
/**
*_isdigit - check if a digit or not
*@c:character in question
*Return: returns 1 if uppercase
*/

int _isdigit(int c)
{
if ((c >= 48) && (c <= 57))
return (1);

return (0);
}
