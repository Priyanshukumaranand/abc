#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;
int count()
{
    int c = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}
int traverse()
{
    int c = 0;
    printf("|%x|\n", head);
    printf("    ");
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("|%x|%d(%x)|%x|-", temp->prev, temp->data, temp, temp->next);
        temp = temp->next;
        c++;
    }
    printf("\nsize of linked list : %d\n", c);
    return c;
}
void traverse_reverse()
{
    struct node *temp;
    head = temp;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("|%d|-", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void insert_back(int data)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL)
    {
        head = ptr;
        printf("INSERTED\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
        printf("INSERTED\n");
    }
}
void insert_front(int data)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        printf("INSERTED\n");
    }
    else
    {
        temp = head;
        ptr->next = temp;
        head = ptr;
        temp->prev = ptr;
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
        struct node *temp, *temp1, *ptr;
        ptr = (struct node *)malloc(sizeof(struct node *));
        ptr->data = data;
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        ptr->prev = temp1;
        ptr->next = temp;
        temp1->next = ptr;
        temp->prev = ptr;
    }
}
void delete_front()
{
    if (head == NULL)
    {
        printf("Linked_list empty!!\n");
    }
    else if (count() == 1)
    {
        head = NULL;
        printf("DELETED!!\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = temp->next;
        temp = temp->next;
        temp->prev = NULL;
        printf("DELETED!!\n");
    }
}
void delete_back()
{
    if (head == NULL)
    {
        printf("Linked_list empty!!\n");
    }
    else if (count() == 1)
    {
        head = NULL;
        printf("DELETED!!\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp = temp->prev;
        temp->next = NULL;
        printf("DELETED!!\n");
    }
}
void delete_btw(int pos)
{
    if (pos == 1)
    {
        delete_front();
        printf("DELETED\n");
    }
    else if (pos == count())
    {
        delete_back();
        printf("DELETED\n");
    }
    else
    {
        struct node *temp, *temp1;
        temp = head;
        for (int i = 1; i <= pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp = temp->next;
        temp1->next = temp;
        temp->prev = temp1;
        printf("DELETED\n");
    }
}
int main()
{
    insert_back(43);
    insert_back(43);
    traverse();
    return 0;
}
