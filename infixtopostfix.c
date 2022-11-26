// implement postfix to infix usign stack

#include <stdio.h>

struct node
{
    char data;
    struct node *next;
} *head = NULL;

void push(struct node *ptr, char c)
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        if (head == NULL)
        {
            head->data = c;
            head->next = NULL;
        }
        else
        {
            temp->data = c;
            temp->next = head;
            head = temp;
        }
    }
}
char pop()
{
    if (head == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        char x = temp->data;
        temp->next = NULL;
        free(temp);
        return x;
    }
}
int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')

        return 1;
    else
    {
        return 0;
    }
}
int operand(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
        return 0;
}



int main()
{

    
}