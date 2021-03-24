#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1000000

typedef struct stack{
    int cap;
    int top;
    char *s;
}stack;


typedef struct queue{
    int cap;
    int front;
    int back;
    char *s;
}queue;

char *input(){
    char *str=malloc(sizeof(char)*LEN);
    scanf("%s",str);
    return str;
}

int isfull(queue *s){
    return(s->back == s->cap -1);
}

void enlarge(queue *s){
    s->cap = s->cap * 2;
    s->s = (char *)realloc(s->s,s->cap*sizeof(char));
}

int isempty(stack *s){
    return(s->top == -1);
}
int pop(stack *s){
    if(s->top == -1)return 0;
    else s->top--;
}
void push(queue *s,char data){
    s->s[s->back++] = data;
    if(isfull(s)){
        enlarge(s);
    }
}

int leftpa(char *s){
}

int righttpa(stack *s){
    for(int i=0;i<s->top;i++){
        if(s->s[i]==')')return 1;
    }
    return 0;
}

float cal(){
    int i=0;
    char *al=0;
    int len,index=1;
    float *ans=0;
    queue *a=malloc(sizeof(queue));
    a->cap=LEN;
    a->s=malloc(sizeof(char)*LEN);
    a->front=0;
    a->back=0;
    al=input();
    for(i=0;i<LEN;i++)if(al[i]==0)break;
    len=i;
    ans = malloc(sizeof(int)*len);
    for(i=0;i<len;i++)ans[i]=al[i]-'0';
    while(index < len){
        if(ans[index]+'0' == '*'){
            ans[index-1] = ans[index-1] * ans[index+1];
            if(index != len-1){
                for(int j=index;j<len-2;j++)ans[j]=ans[j+2];
            }
            len -= 2 ;
        }
        else if(ans[index]+'0'=='/'){
            ans[index-1]=ans[index-1] / ans[index+1];
            if(index != len-1){
                for(int j=index;j<len-2;j++)ans[j]=ans[j+2];
            }
            len -= 2;
        }
        else index+=2;
    }
    index=1;
    while(len > 1){
        if(ans[index]+'0' == '+'){
            ans[index-1] = ans[index-1] + ans[index+1];
            if(index+1 != len-1){
                for(int j=0;j<len-2;j++)ans[j]=ans[j+2];
            }
            len-=2;
        }
        else if(ans[index]+'0' == '-'){
            ans[index-1] = ans[index-1] - ans[index+1];
            if(index+1 != len-1){
                for(int j=0;j<len-2;j++)ans[j]=ans[j+2];
            }
            len-=2;
        }
        else index += 2;
    }
    printf("%f",ans[0]);
}

int main(){
    cal();
    return 0;
}