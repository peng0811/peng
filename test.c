#include <stdio.h>
#include <stdlib.h>


float AVE[5]={0,0,0,0,0};
float AVEmin;
int i;
int AVESrange=5;


float Average(float T,int class,float* ptr);


int main(){
	float input;
	while(1){
		scanf("%f",&input);
		Average(input,1,AVE);
		for(int k=0;k<5;k++)printf("%f\n",AVE[k]);
		printf("%f\n",AVEmin);
	}
return 0;
}

float Average(float T,int class,float* ptr){
float average=0;
if(class=1){
 while(1){
  if(ptr[i]==0){ptr[i]=T;
		break;}
  if(i==AVESrange){
	for(int o=0;o<AVESrange-1;o++)ptr[o] = ptr[o+1];
	ptr[AVESrange-1]=T; 
	break;}
  i++;}
for(int p=0;p<5;p++)average += ptr[p];
AVEmin = average /5;}
return 0;
}
