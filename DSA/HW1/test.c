#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char a[3]={1,2,3};
    a[0]=a[1]*a[2];
    printf("%d",a[0]); 
    return 0;

}