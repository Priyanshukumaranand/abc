#include <stdio.h>
#include <string.h>
char infix[] = "(A*(B+C)*D)";
int size = sizeof(infix) / sizeof(infix[0]);
char stack[10];
int top_stack = -1;
char postfix_stack[20];
int top_expression = -1;
int precedence(char ch)
{
    switch (ch)
    {
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
void postfix()
{
    int i = 0;
    while (i < size)
    {
        if (infix[i] == '(')
        {
            stack[++top_stack] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top_stack > -1 && stack[top_stack] != '(')
            {
                postfix_stack[top_expression++] = stack[top_stack--];}
                if (top_stack > -1 && stack[top_stack] != '(')
                {
                    printf("Invalid string");
                    break;
                }
                else
                    top_stack--;
            
        }
        else if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix_stack[++top_expression] = infix[i];
        }
        else
        {

            if (precedence(infix[i] == 1))
            {
                stack[++top_stack] = infix[i];
                int p = top_stack;
                for (int i = p; i > 0; i--)
                {
                    if (precedence(stack[i - 1]) >= precedence(stack[i]))
                    {
                        postfix_stack[++top_expression] = stack[i - 1];
                        stack[i - 1] = stack[i];
                        top_stack--;
                    }
                }
            }
            else if (precedence(infix[i]) == 2)
            {
                stack[++top_stack] = infix[i];
                int p = top_stack;
                for (int i = p; i > 0; i--)
                {
                    if (precedence(stack[i - 1]) >= precedence(stack[i]))
                    {
                        postfix_stack[++top_expression] = stack[i - 1];
                        stack[i - 1] = stack[i];
                        top_stack--;
                    }
                }
            }
            else if (precedence(infix[i]) == 3)
            {
                stack[++top_stack] = infix[i];
            }
            else
            {
                printf("invalid string");
                // exit(0);
            }
        }
        if (i == size - 1)
        {
            for (int i = top_stack; i > -1; i--)
            {
                postfix_stack[++top_expression] = stack[i];
                top_stack--;
            }
        }
        i++;
    }
}
int main()
{
    postfix();
    printf("\n%d", top_expression);
    printf("\n%d\n", top_stack);

    for (int i = 0; i < top_expression; i++)
    {
        printf("%c", postfix_stack[i]);
    }
    printf("\n");
    for (int i = 0; i < top_stack; i++)
    {
        printf("%c", stack[i]);
    }
    return 0;
}