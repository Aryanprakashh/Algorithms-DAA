#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
    char s[100];
    int top;
    
};
typedef struct Stack stack;

stack push(stack st, char ch){
st.s[++(st.top)]=ch;
return st;
}

char pop(stack st){
    char r=st.s[st.top];
    return r;
}

// precedence

int pre(char c){
    if(c=='/' || c=='*'){
        return 4;
    }
    if(c=='+' || c=='-'){
        return 2;
    }

    if(c=='$'){
        return 3;
    }
    return INT_MIN;
}


int main(){
    char str[100];
    printf("Enter an expression of maximum 100 characters : \n");
    scanf("%s",str);    

    stack s1;
    s1.top=-1;

    char output[100];
    int curr=-1;

    for(int i=0;str[i]!='\0';i++){

        if((str[i]>='a' && str[i]<='z')|| (str[i]>='A' && str[i]<='Z')||(str[i]>='1' && str[i]<='9')){
            output[++curr]=str[i];
            
        }else{


            if(s1.top==-1){             // operator stack is empty
                s1=push(s1,str[i]);
            }

           else if(str[i]==')'){        // founded closing parenthesis

               char ch=pop(s1);
                s1.top--;

                while(ch!='(' && s1.top>-1){
                    output[++curr]=ch;
                     ch=pop(s1);
                     s1.top--;
                }

                ch=pop(s1);

            }

            else{
                    int check=s1.top;
            
                while(pre(s1.s[check])>pre(str[i]) && s1.top>-1){
                    
                    char ch1=pop(s1);
                    
                    if(ch1!='('){
                  output[++curr]=pop(s1); 
                    }

                    s1.top--;
                  check--;
                }

            s1=push(s1,str[i]);

            }

        }
    }


    while(s1.top>=-1){
        output[++curr]=pop(s1);
        s1.top--;
    }

printf("Given postfix notation is : \n");

    printf("%s\n",output);

}


/*
A+(B*C-D/E^F)*G
*/
