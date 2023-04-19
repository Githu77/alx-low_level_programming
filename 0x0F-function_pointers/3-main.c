#include  "3-calc.h"
/**
*main - does add, subtract, division and multiplication
*@argc: no of commands
*@argv: array of commands
*
*
*
*
*
*/
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error\n");
        return 98;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char op = *argv[2];

    int result = calculate(num1, num2, op);

    printf("%d\n", result);
    return 0;
}

/**
*calculate: - handles different operators
*@num1: first number
*@num2: second number
*
*
*
*
*
*/
int calculate(int num1, int num2, char op)
{
    switch (op)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
            {
                printf("Error\n");
                exit(100);
            }
            return num1 / num2;
        case '%':
            if (num2 == 0)
            {
                printf("Error\n");
                exit(100);
            }
            return num1 % num2;
        default:
            printf("Error\n");
            exit(99);
    }
}
