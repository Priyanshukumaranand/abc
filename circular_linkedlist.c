#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int count()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int c = 1;
        struct node *temp;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
            c++;
        }
        return c;
    }
}
void traverse()
{
    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        struct node *temp;
        temp = head;
        printf("|%x|\n", head);
        printf("   ");
        while (temp->next != head)
        {
            printf("|%d(%x)|%x|-", temp->data, temp, temp->next);
            temp = temp->next;
        }
        printf("|%d(%x)|%x|-", temp->data, temp, temp->next);
        printf("\nsize of linked list : %d\n", count());
    }
}
void insert_front(int data)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        head = ptr;
    }
}
void insert_back(int data)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
        printf("INSERTED\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        printf("INSERTED\n");
    }
}
void insert_btw(int pos, int data)
{
    if (pos == 1)
    {
        insert_front(data);
    }
    else if (pos == count() + 1)
    {
        insert_back(data);
    }
    else
    {
        struct node *temp, *ptr;
        ptr = (struct node *)malloc(sizeof(struct node *));
        ptr->data = data;
        ptr->next = NULL;
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void delete_front()
{
    if (head == NULL)
    {
        printf("Linked list empty!!\n");
    }
    else if (count() == 1)
    {
        head = NULL;
        printf("DELETED\n");
    }
    else
    {
        struct node *temp1, *temp2;
        temp1 = head;
        while (temp1->next != head)
        {
            temp1 = temp1->next;
        }
        temp2 = head;
        // temp2=temp2->next;
        temp1->next = temp2->next;
        head = temp2->next;
        printf("DELETED\n");
    }
}
void delete_back()
{
    if (head == NULL)
    {
        printf("Linked list empty!!");
    }
    else if (count() == 1)
    {
        head = NULL;
        printf("DELETED\n");
    }
    else
    {
        struct node *temp, *temp1;
        temp = head;
        while (temp->next != head)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = head;
        printf("DELETED\n");
    }
}
void delete_btw(int pos)
{
    if (head == NULL)
    {
        printf("Linked list empty!!");
    }
    else if (pos == 1)
    {
        delete_front();
    }
    else if (pos == count())
    {
        delete_back();
    }
    else
    {
        struct node *temp1, *temp;
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        printf("DELETED\n");
    }
}
int main()
{
    insert_front(34);
    traverse();
    insert_back(334);
    traverse();
    insert_btw(2, 324);
    traverse();
    delete_btw(2);
    traverse();
    delete_back();
    traverse();
    delete_front();
    traverse();
    return 0;
}