#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 150

char a[LEN];
char b[LEN];

int Input(char n[],char m[]){
    char s[LEN]={0};
    int i,l,j;
    for(i=0;i<LEN;i++){
        n[i]=0;
        m[i]=0;
    }
    if(scanf("%[^\n]",s)<1) return 0;
    for(l=0;l<LEN;l++){
        if(s[l] == ' ')break;
    }
    for(i=0;i<l;i++){
        n[i]=s[l-i-1]-'0';
    }
    for(j=LEN-1;j>l+1;j--){
        if(s[j]!=0)break;
    }
    for(i=j;i>l;i--){
        m[j-i]=s[i]-'0';
    }
   return 0; 
}

void Print(char n[]){
    int i;
    for(i=LEN-1;i>0;i--){
        if(n[i]!=0) break;
    }
    for(int j=0;j<i+1;j++){
        printf("%d",n[j]);
    }
    printf("\n");
}

int compare(char a[],int alen,char b[],int blen){
    if(alen > blen)return 1;     
    else if(alen == blen){
        for(int i=alen-1;i>=0;i--){
            if(a[i]>b[i]) return 1;
            else if(b[i]>a[i]) return 2;
        }
        return 3;
    }
    else{
        return 2;
    }
}

void minus(char m[],int *mlen,char n[],int *nlen){
    int i;
    for(i=0;i<(*mlen);i++){
        m[i]=m[i]-n[i];
        if(m[i]<0){
            m[i]=10+m[i];
            for(int j=i+1;j<(*mlen);j++){
                if(m[j]==0) m[j]=9;
                else{
                    m[j] = m[j]-1;
                    break;
                }
            }
        }
    }
    for(i=(*mlen);i>0;i--){
        if(m[i-1]!=0)break;
    }
    (*mlen)=i;
}

void swap(char m[],int *mlen,char n[],int *nlen){
    char ptr[LEN];
    int len=0;
    for(int i=0;i<LEN;i++)ptr[i]=0;
    len=(*mlen);
    for(int i=0;i<(*nlen);i++){
        ptr[i] = m[i];
        m[i] = n[i];
        n[i] = ptr[i];
    }
    (*mlen) = *nlen;
    *nlen = len; 
}

void divide(char m[],int *mlen){
    int carry=0;
    int c=0;
    for(int i=(*mlen)-1;i>=0;i--){
        c = m[i]+10*carry;
        m[i] = (m[i]+carry*10)/2;
        carry = 0;
        if(c%2!=0) carry=1;
    }
    if(m[(*mlen)-1]==0) (*mlen)=(*mlen)-1;
}

bool zero(char m[],int mlen){
    for(int i=0;i<mlen;i++){
        if(m[i]!=0)return true;
    }
    return false;
}

void multi(char n[],int *nlen){
    int carry=0;
    int c=0;
    for(int i=0;i<*nlen;i++){
        c=n[i];
        n[i] = (c*2+carry)%10;
        carry=0;
        if((c*2+carry)>9)carry=1;
    }
    if(carry == 1){
        n[*nlen]=1;
        (*nlen)=(*nlen)+1;
        }
}

char *GCD(char m[],char n[]){
    int K=0;
    int i=0;
    int mlen=0,nlen=0;
    for(i=LEN-1;i>0;i--){
        if(m[i]!=0)break;
    }
    mlen = i+1;
    for(i=LEN-1;i>0;i--){
        if(n[i]!=0)break;
    }
    nlen = i+1;
    if(compare(m,mlen,n,nlen)==2)swap(m,&mlen,n,&nlen);
    else if(compare(m,mlen,n,nlen)==3){
        for(int j=nlen-1;j>=0;j--)printf("%d",n[j]);
        printf("\n");
        return n;
    }
    while(1){
        if(!zero(m,mlen) || !zero(n,nlen))break;
        if(compare(m,mlen,n,nlen)==3)break;

        if( (m[0]%2==0) && (n[0]%2==0)){
            K++;
            divide(m,&mlen);
            divide(n,&nlen);
        }
        else if((m[0]%2 == 0))divide(m,&mlen);
        else if((n[0]%2 == 0))divide(n,&nlen);
        if(compare(m,mlen,n,nlen)==2)swap(m,&mlen,n,&nlen);
        minus(m,&mlen,n,&nlen);
    }
    for(i=0;i<K;i++)multi(n,&nlen);
    for(i=nlen-1;i>=0;i--)printf("%d",n[i]);
    printf("\n");
    return n;    
}

int main(){
    char *ans=0;
    Input(a,b);
    ans=GCD(a,b);
    return 0;
}