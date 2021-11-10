#include<iostream>
#include<string.h>
using namespace std;
class postfix_infix
{
public:
    char Stack[25][25],infix[50];
    char pfix_exp[50];
    char op1[10],op2[10],res[20];
    int top;
    postfix_infix()
    {
        top=-1;
    }
    void push(char a[])
    {
        strcpy(Stack[++top],a);
    }
    char* pop()
    {
        return Stack[top--];
    }
    void pifix()
    {
        int Count = 0;
        char sym[2];
        while(pfix_exp[Count]!='\0')
        {
            sym[0]=pfix_exp[Count];
            sym[1]='\0';
            if(sym[0]=='+'||sym[0]=='-'||sym[0]=='*'||sym[0]=='/'||sym[0]=='^')
            {
                strcpy(op1,pop());
                strcpy(op2,pop());
                strcpy(res,"(");
                strcat(res,op2);
                strcat(res,sym);
                strcat(res,op1);
                strcat(res,")");
                push(res);
            }
            else
                push(sym);
            Count++;
        }
        strcpy(infix,pop());
        cout<<"Infix expression is : "<<infix;
    }
};
int main()
{
    postfix_infix pi;
    cout<<"enter the postfix expression: ";
    cin>>pi.pfix_exp;
    pi.pifix();
    return 0;
}
