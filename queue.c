#include <stdio.h>
int queue[5];
int front = -1, rear = -1;
int size = sizeof(queue) / sizeof(queue[0]);
void insert(int n)
{
    if (front == -1 || rear == -1)
    {
        queue[++rear] = n;
        front++;
        printf("%d inserted\nfront : %d ,rear : %d\n", n, front, rear);
    }
    else if (rear == size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        queue[++rear] = n;
        printf("%d inserted\nfront : %d ,rear : %d\n", n, front, rear);
    }
}
void delete()
{
    if(front == -1 && rear==-1){
         printf("Queue is empty\n");
    }
    else if(rear==front){
        printf("%d deleted\n",queue[front-1]);
        rear=-1;
        front=-1;
         printf("front : %d ,rear : %d\n", front, rear);
        }
    else{
        front++;
        printf("%d deleted\nfront : %d ,rear : %d\n",queue[front-1], front, rear);
    }
}
int main()
{
    int t=9,n;
    while(t!=0){
       printf("0:EXIT\n1:INSERT\n2:DELETE\n");
       printf("Enter your choice :");
       scanf("%d",&t);
       if(t==1){
         printf("enter the element to insert : ");
         scanf("%d",&n);
         insert(n);
       }
       else if(t==2){
        delete();
       }
       else{t=0;}
    }
    return 0;
}