#include <stdio.h>
int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];
void push(int item)
{
    if (top == 19)
        printf("stack full");
    else
        stack[++top] = item;
}
int delete()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return k;
    }
}
int pop()
{
    int k;
    if (top == -1)
        return 0;
    else
    {
        k = stack[top--];
        return k;
    }
}
int add(int item)
{
    if (rear == 19)
        printf("FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
        printf("%d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf("%d", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}
void dfs(int s, int n)
{
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0)
        printf("%d", k);
    while (k != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[k][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        k = pop();
        if (k != 0)
            printf("%d", k);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i, n);
}
int main()
{
    int n, i, s, ch, j,E, v0, v1,ve;
    char c, dumy;
    printf("Enter vertices : ");
    scanf("%d", &n);
    printf("Enter edges : ");
    scanf("%d", &E);
    for (i = 1; i <= E; i++)
    {
        printf("Enter v - v1 : ");
        scanf("%d %d", &v0, &v1);
        a[v0][v1] = 1;
        a[v1][v0] = 1;
    }
    printf("Adjancency matrix : ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    do
    {
        for (i = 1; i <= n; i++)
            vis[i] = 0;
        printf("\n1.BFS");
        printf("\n2.DFS");
        printf("\n3.Insert edge/vertex");
        printf("\n4.Delete edge/vertex");
        printf("\nEnter choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the source vertex : ");
            scanf("%d", &s);
            bfs(s, n);
            break;
        case 2:
            printf("Enter the source vertex : ");
            scanf("%d", &s);
            dfs(s, n);
            break;
        case 3:
            printf("Enter v0 - v1 : ");
            scanf("%d %d", &v0, &v1);
            a[v0][v1] = 1;
            a[v1][v0] = 1;
            if(v0>n || v1>n)
               n++;
            break;
        case 4:
            printf("Enter v0 - v1 : ");
            scanf("%d %d", &v0, &v1);
            a[v0][v1] = 0;
            a[v1][v0] = 0;
            n--;
            break;
        }
        printf("\nWanna continue?(Y/N) : ");
        scanf("%c", &dumy);
        scanf("%c", &c);
    } while ((c == 'y') || c == 'Y');

    return 0;
}