#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void debug(){
    while(1){
        int p;
        scanf("\n%d",&p);
        if(p==1)break;
    }
}



int *input(int,int*);
bool recur(char**,int*,int*,int);
bool detect(char **,int);
bool valid(char **,int*,int *,int);

int main(){
char **ptr=0;
char *ptr1=0;
int *low_lim=0;
int *col_lim=0;
int lownum;
int colnum;
int LAST=0;
int COL;
int LOW;
/*decide COL/LOW*/
printf("input COL and LOW:");
scanf("%d",&COL);
scanf("%d",&LOW);
ptr1=malloc(sizeof(char)*(COL*LOW));
ptr=malloc(sizeof(char *)*COL);
for(int i=0;i<COL*LOW;i++)ptr1[i]='x';
for(int j=0;j<COL;j++)ptr[j]=&ptr1[j*COL];
/**/
/*decide limit*/
printf("input low limit:\n");
low_lim=input(LOW,&lownum);
printf("input col limit:\n");
col_lim=input(COL,&colnum);
/**/
while(LAST<lownum){
    for(int i=0;i<=low_lim[LAST];i++){
        printf("%d",low_lim[LAST+i]);
    }
    printf("\n");
    LAST=LAST+low_lim[LAST]+1;
}
LAST =0;
while(LAST<colnum){
    for(int i=0;i<=col_lim[LAST];i++){
        printf("%d",col_lim[LAST+i]);
    }
    printf("\n");
    LAST=LAST+col_lim[LAST]+1;
}
    //int lowlim[10]={1,4,1,2,1,3,1,2,1,4};
    //int collim[16]={2,1,1,2,3,1,3,1,1,1,2,1,3,2,1,1};
    //char **ptr=0;
    //char **ptr1=0;
    //char p[5][5]={{'_','o','o','o','o'},
                    //{'o','o','_','_','_'},
                    //{'_','o','o','o','_'},
                    //{'_','_','_','o','o'},
                    //{'o','o','o','o','_'}};
    //char p1[5][5]={{'x','x','x','x','x'},
                    //{'x','x','x','x','x'},
                    //{'x','x','x','x','x'},
                    //{'x','x','x','x','x'},
                    //{'x','x','x','x','x'}};

    //ptr=malloc(sizeof(char*)*COL);
    //for(int i=0;i<COL;i++)ptr[i]=p[i];

    //ptr1=malloc(sizeof(char*)*COL);
    //for(int i=0;i<COL;i++){
        //ptr1[i]=p1[i];
    //}


recur(ptr,low_lim,col_lim,COL);
}

int *input(int count,int *size){
    int *ptr=0;
    int NUM=0;
    for(int i=1;i<=count;i++){
        int input;
        printf("input %d limit numbers:",count);
        scanf("%d",&input);
        ptr=realloc(ptr,sizeof(int)*(input+1+NUM));
        ptr[NUM]=input;
        printf("input limit:\n");
        for(int i=0;i<input;i++){
            scanf("%d",&ptr[NUM+1+i]);
        }
         NUM=NUM+(input+1);
    }
    *size=NUM;
    return ptr;
}


bool recur(char **ptr,int *lowlim,int *collim,int len){
    int low=0;
    int col=0;
    bool succeed;
    if(detect(ptr,len)){
        if(valid(ptr,lowlim,collim,len)){
            for(int i=0;i<len;i++){
                for(int j=0;j<len;j++){
                    printf("%c ",ptr[i][j]);
                }
                printf("\n");
            }
            return true;
        }
        else return false;
    }
    while(1){
        if(ptr[low][col]=='x')break;
        if(col==(len-1)){
            col=0;
            low++;
        }
        else{col++;}
    }
    ptr[low][col]='o';
    succeed = recur(ptr,lowlim,collim,len);
    if(succeed){
        return true;
    }
    ptr[low][col]='_';
    succeed = recur(ptr,lowlim,collim,len);
    if(succeed){
        return true;
    }
    ptr[low][col]='x';
    return false;
}

bool detect(char **ptr,int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(ptr[i][j]=='x'){
                //printf("no filled\n");
                return false;
            }
        }
    }
    //printf("is filled\n");
    return true;
}


bool valid(char **ptr,int *lowlim,int *collim,int len){
    bool cor=false;
    int low_su=0;
    int col_su=0;
    int count=0;
    int last=0;
    int *cir=0;
    int c=0;
    int CIR=0;
   for(int i=0;i<len;i++){
        c=0;
        count=0;
        free(cir);
        CIR=0;
        cir=0;
        while(count<len){
            if(ptr[i][count]=='o'){
                CIR=0;
                while(ptr[i][count]=='o'&&count<len){
                    CIR++;
                    count++;
                    if(count==len)break;
                }
            cir=realloc(cir,sizeof(int)*(c+1));
            cir[c]=CIR;
            c++;
            }
            else count++;
        }
        if(lowlim[last]!=c)return false;
        if(CIR!=0){
            for(int j=0;j<lowlim[last];j++){
                if(lowlim[last+1+j]!=cir[j])return false;
                else cor=true;
            }
        }
        if(cor){
            //printf("right\n");
            low_su++;
        }
        last = last + lowlim[last] + 1;
    }
    last=0;
    for(int i=0;i<len;i++){
        c=0;
        count=0;
        free(cir);
        CIR=0;
        cir=0;
        while(count<len){
            if(ptr[count][i]=='o'){
                CIR=0;
                while(ptr[count][i]=='o'&&count<len){
                    CIR++;
                    count++;
                    if(count==len)break;
                }
            cir=realloc(cir,sizeof(int)*(c+1));
            cir[c]=CIR;
            c++;
            }
            else count++;
        }
        if(collim[last]!=c)return false;
        if(CIR!=0){
            for(int j=0;j<collim[last];j++){
                if(collim[last+1+j]!=cir[j])return false;
                else cor=true;
            }
        }
        if(cor){
            //printf("right\n");
            col_su++;
        }
        last = last + collim[last] + 1;
    }
    if(low_su==len&&col_su==len)return true;
    else return false;

}