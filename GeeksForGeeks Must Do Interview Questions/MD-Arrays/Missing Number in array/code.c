#include <stdio.h>
#include<stdlib.h>
int findMissing(int);

int main() {
    int T,N,n;
	scanf("%d", &T);
    int * missing=(int *)malloc(sizeof(int)*T);
	for(int i=0;i<T;i++){
	    scanf("%d",&N);
        missing[i]=findMissing(N);
        }
        for(int i=0;i<T;i++)
        printf("%d\n",missing[i]);
	return 0;
}


int findMissing(int len){
int C[len-1];
long sum;
for(int i=0;i<len-1;i++)
    scanf("%d",&C[i]);
sum=len*(len+1)/2;
for(int i=0;i<len-1;i++)
    sum-=C[i];
    return (int)sum;
}