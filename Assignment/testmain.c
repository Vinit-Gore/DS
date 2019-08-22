#include<stdio.h>

void mergesort(int [], int);
void main(){
    int arr[10] = {20,30, 40, 10,  100, 50,  60,  90,  80,  70};
    quicksort(arr,10);
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
}