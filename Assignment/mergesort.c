#include<limits.h>
void merge_sort(int [], int, int);     //My declaration
void merge(int [], int, int ,int);

void mergesort(int array[], int size){      //Called in the main
    int p=0, r=size-1;
   merge_sort(array,p,r);
};

void merge_sort(int array[], int p, int r)      
{
if(p<r)
{
    int q=(p+r)/2;
    merge_sort(array,p,q);
    merge_sort(array,q+1,r);
    merge(array,p,q,r);
}
}

void merge(int array[], int p, int q, int r){

int n1=q-p+1;
int n2=r-q;
int L[n1+1], R[n2+1];
for(int i=0;i<n1;i++)    L[i]=array[p+i];
for(int i=0;i<n2;i++)    R[i]=array[q+i+1];
L[n1]=INT_MAX;
R[n2]=INT_MAX;
int i=0, j=0, k=p;
while(i<n1 && j<n2){
    if(L[i]<=R[j]) { 
        array[k++] = L[i++];
    }
    else   {
        array[k++] = R[j++];
    }
}

while(i<n1) array[k++]=L[i++];
while(j<n2) array[k++]=R[j++];
}