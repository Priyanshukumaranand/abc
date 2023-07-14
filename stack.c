#include <stdio.h>
int stack[10];
int top = -1;
void push(int n)
{
    int size = sizeof(stack) / sizeof(stack[0]);
    if (top == size - 1)
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        stack[top + 1] = n;
        top = top + 1;
        printf("%d inserted \nNew top : %d\n",n, top);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        top = top - 1;
        printf("%d at top : %d deleted\n", stack[top + 1], top + 1);
        printf("top : %d\n", top);
    }
}
int main()
{
    push(3);
    return 0;
    push(38);
    push(38);
    push(38);
    push(38);
    push(73);
    push(63);
    push(63);
    push(63);
    push(63);
    push(63);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}