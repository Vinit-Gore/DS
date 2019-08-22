#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int array[], int n)
{
time_t t;
time(&t);//get current time
srand(t);//gives current time as seed for random number generator
for(int i = 0; i < n; i++)
{
array[i] = rand()%(10*n);//Doing mod to avoid very large numbers
}
}
void printArray(int array[], int n)
{
for(int i = 0; i < n; i++)
{
printf("%d ", array[i]);
}
}
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
void bubbleSort(int array[], int n)
{
    int swapped, i, j, count_swap;
     for (i=0;i<n-1;i++)
    {
        swapped = 0;
        count_swap = 0;
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]) {
                swap(&array[j],&array[j+1]);
                count_swap++;
               swapped =1;
            }
        }
       if(swapped == 0) break;
    printf("Number of swaps for pass %d: %d\n",i, count_swap);
    }
}
int main()
{
int * array, n;
printf("Enter the no. of numbers: ");
scanf("%d", &n);
array = malloc(n * sizeof(int));
fillArray(array, n);
// for(int i=1;i<=n;i++)
// array[i]=i;
bubbleSort(array, n);
printArray(array, n);
}