#include<stdio.h>

int stack[30];
int top=-1;

void push(int x){
    stack[++top]=x;
}
int pop(){
    if(top==-1){
        return -1;
    }
    else
    return stack[top--];
}

int main(){
    char str[30];
    char *e;
    printf("Enter Expression\n");
    scanf("%s",&str);

    e=str;
    while(*e!='\0'){
        if((int)*e>=48 && (int)*e<=57){
            push((int)(*e)-48);
        }
        else if((int)(*e)==43){
            int a=pop();
            int b=pop();
            push(a+b);
        }
        else if((int)(*e)==42){
            int a=pop();
            int b=pop();
            push(a*b);

        }
        else if((int)(*e)==45){
            int a=pop();
            int b=pop();
            push(b-a);
        }
        else if((int)(*e)==47){
            int a=pop();
            int b=pop();
            push(b/a); 
        }
        e++;
    }
    printf("Final Output : ");
    printf("%d",pop());

    return 0;
}