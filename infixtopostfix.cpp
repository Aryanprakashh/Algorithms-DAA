// implement postfix to infix usign stack
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
} *head = NULL;

void push(char c)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
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
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
char top()
{
    if (isEmpty())
        return -1;
    return head->data;
}
int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if ((c == '^'))
        return 3;

    return -1;
}
int isOperand(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
        return 0;
}
// exp-->expression
int infixTopostfix(char *exp)
{
    int k=-1;
    for (int i = 0; i < exp[i]!='\n'; i++)
    {
        if(isOperand(exp[i])){
            exp[++k]=exp[i];
        }
        else if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(!isEmpty() and top()!='('){
                exp[++k]=pop();
            }
            if(!isEmpty() and top()!='('){
                return -1;
            }
            else pop();
        }
        //operator
        else{
            while(!isEmpty() && prec(exp[i])<prec(top()))   //check precedence of operator
            exp[++k]=pop();

            push(exp[i]);
        }
    }
    while(!isEmpty())
        exp[++k]=pop();
        exp[++k]='\0';
        printf("%s",exp);
    
}
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
  
    // Function call
    infixTopostfix(exp);
    cout<<exp;
    // cout<<exp;
    return 0;
    
}