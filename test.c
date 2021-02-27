#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *nxt;
}node;

node *alloc(int data,node *nxt){
	node *tmp=(node *)malloc(sizeof(node));
	tmp->data=data;
	tmp->nxt=nxt;
	return tmp;
}

node *input(){
	node *head=NULL;
	while(1){
		int input;
		scanf("%d",&input);
		if(input==10)break;
		head=alloc(input,head);
	}
	return head;
}

node *add(node *tmp1,int l1,node *tmp2,int l2){
	int a;
	int b;
	int carry=0;
	if(l1>l2){
		for(int i=1;i<=l1;i++){
			
			if(i>l2){
				if(carry==1)a=tmp1->data+1;
				carry=0;
			}
			else{
				if(carry==1){
					a=tmp1->data+tmp2->data+1;
					carry=0;
				}
				else a=tmp1->data+tmp2->data;
			}
			
			if(a>9){
				carry=1;
				tmp1->data = a%10;
			}
			else tmp1->data=a;

			tmp1=tmp1->nxt;
			tmp2=tmp2->nxt;
			if(tmp1->nxt==NULL&&carry==1){
				node *t = (node *)malloc(sizeof(node));
				tmp1->data=1;
				tmp1->nxt=t;
				t->nxt=NULL;
			}
		}
	}
	else if(l2>l1){}
	else{}
}

int main(){
	node *tmp1;
	int l1=0;
	node *tmp2;
	int l2=0;
	tmp1 = input();
	tmp2 = input();
	while(tmp1!=NULL){
		printf("%d ->",tmp1->data);
		tmp1=tmp1->nxt;
		l1++;
	}
	printf("NULL");
	while(tmp2!=NULL){
		printf("%d ->",tmp2->data);
		tmp2=tmp2->nxt;
		l2++;
	}
	printf("NULL");
	add(tmp1,l1,tmp2,l2);
	if(l1>=l2){
		while(tmp1!=NULL){
			printf("%d",tmp1->data);
			tmp1=tmp1->nxt;
		}
		printf("\n");
	}
	else if(l2>l1){
		while(tmp2!=NULL){
			printf("%d",tmp2->data);
			tmp2=tmp2->nxt;
		}
		printf("\n");
	}	
return 0;
}
