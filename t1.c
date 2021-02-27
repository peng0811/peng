#include <stdio.h>
#include <stdlib.h>

#define MINN -4
#define MAXX 4

int main(){
	char *ptr=0;
    char **ptr1=0;
    ptr=malloc(sizeof(char)*25);
    ptr1=malloc(sizeof(char*)*5);
    for(int i=0;i<25;i++)ptr[i]='o';
    for(int j=0;j<5;j++)ptr1[j]=&ptr[j*5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%c",ptr1[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}