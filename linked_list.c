#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int traverse()
{
    int c = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("|%d|-", temp->data);
        temp = temp->next;
        c++;
    }
    printf("\nsize of linked list : %d\n", c);
    return c;
}
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
void insert_front(int data)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    printf("INSERTED\n");
}
void insert_back(int data)
{
    struct node *ptr, *temp, *temp1;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    printf("INSERTED\n");
}
void insert_btw(int pos, int data)
{
    struct node *ptr, *temp, *temp1, *temp2;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = NULL;
    int b = count();
    if (pos == 1)
    {
        insert_front(data);
    }
    else if (pos == b + 1)
    {
        insert_back(data);
    }
    else if (pos > b || pos < 1)
    {
        printf("element can be inserted from position 0 to %d !!\n", b);
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        ptr->next = temp;
        temp1->next = ptr;
        printf("INSERTED\n");
    }
}
void delete_front()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *temp;
        temp = head;

        head = temp->next;
        free(temp);
        printf("DELETED\n");
    }
}
void delete_back()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *temp, *temp1;
        temp = head;

        if (temp->next == NULL)
        {
            head = NULL;
        }
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        temp1->next = NULL;
        printf("DELETED\n");
    }
}
int delete_btw(int pos)
{
    int b = count();
    if (pos > b || pos <= 0)
    {
        printf("position should be less than list size and more than 0\n");
    }
    else
    {
        if (head == NULL)
        {
            printf("Linked list is empty\n");
        }
        else
        {
            struct node *temp, *temp1;
            temp = head;
            if (pos == 1)
            {
                delete_front();
            }
            else if (pos == count())
            {
                delete_back;
            }
            else
            {
                for (int i = 1; i < pos; i++)
                {
                    temp1 = temp;
                    temp = temp->next;
                }
                temp1->next = temp->next;
                temp->next = NULL;
            }
            printf("DELETED\n");
        }
    }
}
int main()
{
    int t = 9, n;
    while (t != 0)
    {
        printf("0:EXIT\n1:INSERT\n2:DELETE\n");
        printf("Enter your choice :");
        scanf("%d", &t);
        if (t == 1)
        {
            int ins = 9, m, posi;
            while (ins != 0)
            {
                printf("1:INSERT TOP\n2:INSERT BTW\n3:INSERT BACK\n0:EXIT\n");
                printf("Enter your choice :");
                scanf("%d", &ins);
                if (ins == 1)
                {
                    printf("Enter the num :");
                    scanf("%d", &m);
                    insert_front(m);
                    traverse();
                }
                else if (ins == 2)
                {
                    printf("Enter the num :");
                    scanf("%d", &m);
                    printf("Enter the position :");
                    scanf("%d", &posi);
                    insert_btw(posi, m);
                    traverse();
                }
                else if (ins == 3)
                {
                    printf("Enter the num :");
                    scanf("%d", &m);
                    insert_back(m);
                    traverse();
                }
                else
                {
                    ins = 0;
                }
            }
        }
        else if (t == 2)
        {

            int ins = 9, posi;
            while (ins != 0)
            {
                printf("1:DELETE TOP\n2:DELETE BTW\n3:DELETE BACK\n0:EXIT\n");
                printf("Enter your choice :");
                scanf("%d", &ins);
                if (ins == 1)
                {
                    delete_front();
                    traverse();
                }
                else if (ins == 2)
                {
                    printf("Enter the position :");
                    scanf("%d", &posi);
                    delete_btw(posi);
                    traverse();
                }
                else if (ins == 3)
                {
                    delete_back();
                    traverse();
                }
                else
                {
                    ins = 0;
                }
            }
        }
        else
        {
            t = 0;
        }
    }
    return 0;
}