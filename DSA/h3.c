#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node{
    int data;
    struct node *nxt;
}node;

node *alloc(int data,node *nxt){
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->nxt = nxt;
}

void destroy(node *head){
    if(head != NULL ){
        destroy(head->nxt);
        memset(head,0,sizeof(head));
        free(head);
    }
}

int main(){
    node *head=alloc(0,alloc(1,alloc(2,alloc(4,NULL))));
    node *tmp=head;

    while(tmp != NULL){
        printf("%d ->",tmp->data);
        tmp = tmp->nxt;
    }
    printf("NULL");

    destroy(head);
    return 0;
}