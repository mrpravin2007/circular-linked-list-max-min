#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp;
    int i, n;
    int max, min;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return 0;
    }

  
    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }


    temp->next = head;

  
    printf("\nCircular Linked List: ");

    temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("back to head\n");


    max = head->data;
    min = head->data;

    temp = head;

    do
    {
        if (temp->data > max)
        {
            max = temp->data;
        }

        if (temp->data < min)
        {
            min = temp->data;
        }

        temp = temp->next;

    } while (temp != head);

    printf("\nMaximum number = %d", max);
    printf("\nMinimum number = %d", min);

    return 0;
}
