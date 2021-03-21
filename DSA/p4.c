#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define L 1000
#define T 1000

double po[L][T];
char stack[L];
double dstack[L];
int top=-1;
int dtop=-1;

bool isempty(){
    return (top < 0 ? true : false);
}

bool disempty(){
    return (dtop<0?true:false);
}

void push(char a){
    if(top>=L-1){
        printf("full");
        exit(-1);
    }
    stack[++top]=a;
}

void dpush(double a){
    if(dtop>=L-1){
        printf("full");
        exit(-1);
    }
    dstack[++dtop] = a;
}

char pop(){
    if(isempty()){
        printf("empty");
        exit(-1);
    }
    return stack[top--];
}

double dpop(){
    if(disempty()){
        printf("empty");
        exit(-1);
    }
    return dstack[dtop--];
}

char check_top(){
    return stack[top];
}

bool isDigit(char a){
    return (a>='0' && a <='9');
}

double interge(){
    int index=0;
    double num1=0;
    double num2=1;
    while(!disempty()){
        num2 = dpop();
        for(int i=0;i<index;i++)num2 = num2*10;
        num1 = num1 + num2;
        index++;
    }
    dpush(num1);
}


int prio(char a){
    char p[5]={'(','+','-','*','/'};
    int Prio[5]={0,1,1,2,2};
    int i;
    for(i=0;i<5;i++){
        if(p[i]==a)return Prio[i];
    }
    return -1;
}

void change(char *in,double *po){
    int i=0,j=-1,k=0;
    char x,y;
    while((x=in[i++])!= 0){
        switch(x){
            case '(':
                push(x);
                break;
            case ')':
                interge();
                po[++j] = dpop();
                while( !isempty() && (x=pop())!='('){
                    po[++j] = x-'0';
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':y=check_top();
                        if(!disempty()){
                            interge();
                            po[++j] = dpop();}
                        while(prio(y) >= prio(x)){
                            po[++j] = pop()-'0';
                            y=check_top();
                        }
                        push(x);
                        break;
            default:dpush(x-'0');
        }
    }
    while(!disempty()){
        interge();
        po[++j] = dpop();
    }
    while(!isempty()){
        po[++j]=pop()-'0';
    }
    po[++j]=0;
}

double cal(double *po){
    int index=0;
    while(po[index]!=0){
        while(po[index] >= 0){
            dpush(po[index++]);
        }
        double op1 = dpop();
        double op2 = dpop();
        double c=0;
        char s=po[index]+'0';
        switch(s){
            case '+':c=op2+op1;
                        break;
            case '-':c=op2-op1;
                        break;
            case '*':c=op2*op1;
                        break;
            case '/':c=op2/op1;
                        break;
        }
        dpush(c);
        index++;
    }
    return dpop();   
}

int main(){
    char **al=malloc(sizeof(char *));
    int index=0,i;
    while(1){
        char *str=malloc(sizeof(char)*L);
        if(fgets(str,L,stdin)==NULL)break;
        al[index]=str;
        if(al[index][0] == '\n')break;
        for(i=0;i<L;i++){
            if(al[index][i] == '\n')al[index][i] =0;
        }
        index++;
        al = realloc(al,sizeof(char *)*(index+1));
    }
    double ans;
    for(i=0;i<index;i++){
        change(al[i],po[i]);
        ans=cal(po[i]);
        printf("%f\n",ans);
    }
    return 0;
}

