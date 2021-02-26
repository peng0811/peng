#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void *input(int i);
void rev(int* ptr,int Len);
bool zero(int*,int);
bool comparator(int* a,int length_a,int* b,int length_b);
bool same(int*,int,int*,int);
void sub(int*,int*,int*,int*);
void divide_two(int*,int*);
void multi_two(int*);
void swap(int*,int*);
void ans(int*,int,int);

typedef struct 
{
	int *a;
	int *b;
	int length[2];
}a_b;

typedef struct{
	int* n;
	int length;
}MIN;

typedef struct
{
	int* m;
	int length;
}MAX;

a_b ab={
	.a=0,.b=0,
	.length[0]=0,.length[1]=0
};


void main(){
int COUNT=0;
MIN N={
	.n=NULL,
	.length=0
};
MAX M={
	.m=NULL,
	.length=0
};
/*輸入*/
printf("input a=\n");
ab.a=input(0);
printf("input b=\n");
ab.b=input(1);
/**/

/*反轉*/
printf("a=");
rev(ab.a,ab.length[0]);
for(int i=0;i<ab.length[0];i++)printf("%d",ab.a[i]);
printf("\n");

printf("b=");
rev(ab.b,ab.length[1]);
for(int i=0;i<ab.length[1];i++)printf("%d",ab.b[i]);
printf("\n");
/**/
if(!zero(ab.a,ab.length[0])||!zero(ab.b,ab.length[1]))printf("有一為零\n");
if(!same(ab.a,ab.length[0],ab.b,ab.length[1]))printf("a和b一樣\n");
/*a!=b and a!=0 and b!=0**/
if(zero(ab.a,ab.length[0])&&zero(ab.b,ab.length[1])&&same(ab.a,ab.length[0],ab.b,ab.length[1])){
	if(comparator(ab.a,ab.length[0],ab.b,ab.length[1])==false){ 
		N.n = malloc(sizeof(int)*ab.length[0]);
		N.length = ab.length[0];
		for(int i=0;i<ab.length[0];i++)N.n[i]=ab.a[i];
		M.m = malloc(sizeof(int)*ab.length[1]);
		M.length = ab.length[1];
		for(int i=0;i<ab.length[1];i++)M.m[i]=ab.b[i];
		//printf("b\n");
		}
	else if(comparator(ab.a,ab.length[0],ab.b,ab.length[1])==true){
		M.m = malloc(sizeof(int)*ab.length[0]);
		M.length = ab.length[0];
		for(int i=0;i<ab.length[0];i++)M.m[i]=ab.a[i];
		N.n = malloc(sizeof(int)*ab.length[1]);
		N.length = ab.length[1];
		for(int i=0;i<ab.length[1];i++)N.n[i]=ab.b[i];
		//printf("a\n");
		}
//printf("n為");
//for(int i=0;i<N.length;i++)printf("%d",N.n[i]);
//printf("\n");
//printf("m為");
//for(int i=0;i<M.length;i++)printf("%d",M.m[i]);
//printf("\n");

while(1){
/*判斷是否為零*/
	if(!zero(M.m,M.length)||!zero(N.n,N.length))break;//判斷是否跳出迴圈
/**/
	if(!same(M.m,M.length,N.n,N.length))break;
/*判斷是否為偶數*/
	if((N.n[0]%2)==0&&(M.m[0]%2)==0){
		COUNT++;
		divide_two(N.n,&N.length);
		divide_two(M.m,&M.length);
		}
	else if((N.n[0]%2)==0)divide_two(N.n,&N.length);
	else if((M.m[0]%2)==0)divide_two(M.m,&M.length);
	/**/
	printf("n=");
	for(int i=0;i<N.length;i++)printf("%d",N.n[i]);
	printf("\n");
	printf("m=");
	for(int i=0;i<M.length;i++)printf("%d",M.m[i]);
	printf("\n");
	if(!same(M.m,M.length,N.n,N.length))break;

	/*若n>m，交換*/
	if(!comparator(M.m,M.length,N.n,N.length)){
		int* swap=0;
		int len;
		swap=M.m;
		len=M.length;
		M.m=N.n;
		M.length=N.length;
		N.n=swap;
		N.length=len;
	}
	/**/
	printf("n=");
	for(int i=0;i<N.length;i++)printf("%d",N.n[i]);
	printf("\n");
	printf("m=");
	for(int i=0;i<M.length;i++)printf("%d",M.m[i]);
	printf("\n");

	/*m=m-n*/
	sub(M.m,&M.length,N.n,&N.length);
	/**/
	printf("n=");
	for(int i=0;i<N.length;i++)printf("%d",N.n[i]);
	printf("\n");
	printf("m=");
	for(int i=0;i<M.length;i++)printf("%d",M.m[i]);
	printf("\n");
	printf("%d",M.length);
	if(!same(M.m,M.length,N.n,N.length))break;

	//while(1){
//		int p;
//		scanf("%d",&p);
//		if(p==1)break;
//	}
	}
	for(int i=0;i<N.length;i++)printf("%d",N.n[i]);
	printf("\n");
	printf("%d",COUNT);
	printf("\n");
	ans(N.n,COUNT,N.length);
}
else if(!zero(ab.a,ab.length[0])){/*a為0*/
	printf("答案為");
	for(int i=0;i<ab.length[1];i++)printf("%d",ab.b[i]);
}
else if(!zero(ab.b,ab.length[1])){/*b為0*/
	printf("答案為");
	for(int i=0;i<ab.length[0];i++)printf("%d",ab.a[i]);
}
else if(!same(ab.a,ab.length[0],ab.b,ab.length[1])){/*a=b*/
	printf("答案為");
	for(int i=0;i<ab.length[0];i++)printf("%d",ab.a[i]);
}
}

void *input(int i){
	int *ptr=0;
	while(1){
		int input;
		scanf("%d",&input);
		if(input== 10)break;
		ptr = realloc(ptr,sizeof(int)*(ab.length[i] + 1));
		ptr[ab.length[i]]=input;
		ab.length[i]++;}
	return ptr;
}

void rev(int* ptr,int Len){	
	int a=0;
	for(int i=0;i<Len/2;i++){
		a=ptr[i];
		ptr[i]=ptr[Len-1-i];
		ptr[Len-1-i]=a;}
}

bool comparator(int* a,int length_a,int* b,int length_b){
	bool wholarger=true;
	if(length_a < length_b)wholarger=false;
	if(length_a > length_b)wholarger=true;
	if(length_a == length_b){
	for(int i=0;i<length_a;i++){
		if(a[length_a-1-i]<b[length_a-1-i]){wholarger = false;
		break;}
		if(a[length_a-1-i]>b[length_a-1-i]){wholarger = true;
		break;}
		}
	}
return wholarger;
}

bool zero(int* ptr,int Len){
	int count=0;
	for(int i=0;i<Len;i++){
		if(ptr[i]==0)count++;}
	if(count==Len)return false;
	return true;}

void divide_two(int* ptr,int* L){
int R=0,D=0;
int len=0;
len = *L;
	for(int i=0;i<len;i++){
		D=R*10+ptr[len-1-i];
		R=D%2;
		ptr[len-1-i]=D/2;
	}
	if(ptr[len-1]==0){(*L)=len-1;}
}

void sub(int* ptr_m,int* len_m,int* ptr_n,int* len_n){
int max=0,count=0;
max = *len_m;
for(int i=0;i<max;i++){
	if(ptr_m[i]>ptr_n[i])ptr_m[i]=ptr_m[i]-ptr_n[i];
	else if(ptr_m[i]==ptr_n[i])ptr_m[i]=0;
	else if(ptr_m[i]<ptr_n[i]){
			ptr_m[i]=(10-ptr_n[i])+ptr_m[i];
			int comp=i+1;
			while(1){
				if(ptr_m[comp]==0){
					ptr_m[comp]=9;
					comp++;
				}
				else if(ptr_m[comp]!=0){
					ptr_m[comp]=ptr_m[comp]-1;
					break;
				}
			}
		}
}
int j;
j=max-1;
while(1){
	if(ptr_m[j]==0)count++;
	if(ptr_m[j]!=0)break;
	j--;
}
if(max>1){
	if(max==count)	*len_m=1;
	else *len_m=max-count;
}
}

bool same(int* mm,int lenm,int* nn,int lenn){
int count=0;	
	if(lenm==lenn){
		for(int i=0;i<lenm;i++){
			if(mm[i] == nn[i])count++;
		}
	}
	else return true;
	if(count == lenm)return false;
	else return true;
}

void ans(int* ptr,int count,int len){
int carry=0;
	for(int i=0;i<count;i++){
		for(int j=0;j<len+1;j++){
			if(carry==1){
				if(((2*ptr[j])+carry)>=10){
					carry=1;
					ptr[j]=2*ptr[j]+carry-10;
				}
				else{
					ptr[j]=2*ptr[j]+carry;
					carry=0;
				}
			}
			else{
				if((2*ptr[j])>=10){
					carry=1;
					ptr[j]=2*ptr[j]-10;
				}
				else{
					ptr[j]=2*ptr[j];
				}
			}
		}
	}	
printf("ans=");
for(int i=0;i<len+1;i++)printf("%d",ptr[i]);
}