#include<stdio.h>
#include<stdlib.h>

void quicksort(int array[], int size);
void mergesort(int array[], int size);
void heapsort(int array[], int size);

void printarray(int array[], int size)
{
int i;
for(i = 0; i < size; i++)
{
printf("%d ", array[i]);
}
printf("\n");
}
void swap(int *a, int *b)
{
int temp = *a;//saving *a
*a = *b;
*b = temp;
}
void bubblesort(int array[], int size)
//When an array is passed to a function in C, it is treated as a pointer to the respective datatype. There is no use in specifying the size here
{
    int swapped, i, j, count_swap =0;
     for (i=0;i<size-1;i++)
    {
        swapped = 0;
        for(j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]) {
                swap(&array[j],&array[j+1]);
                count_swap++;
               swapped =1;
            }
        }
       if(swapped == 0) break;
    }
    printf("Number of swaps: %d\n", count_swap);
//Anything to return?
}
void selectionsort(int array[], int size)
{
    int pos, j, swaps = 0;
    for(pos = 0; pos < size-1; pos++){
        j = pos;
        for(int i=pos+1;i<size;i++){
            if(array[i]<array[j]) j=i;
        }
        swap(&array[pos],&array[j]);
        swaps++;
    }
    printf("Number of swaps: %d\n", swaps);
}
//Try to make this decreasing sort
void insertionsort(int array[], int size)
{   int swaps =0;
    for(int i=1;i<size;i++){
        int picked = array[i];
        int j = i-1;       
        while(array[j]>picked && j>=0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=picked;
        swaps++;
    }
    printf("Number of swaps: %d\n", swaps);
}
int* copyandcreatearray(int *src, int size)
{
int *dest = (int*) malloc(size* sizeof(int));
for(int i = 0; i < size; i++)
dest[i] = src[i];
return dest;
}
void copyarray(int *src,int *dest, int size)
{
for(int i = 0; i < size; i++)
dest[i] = src[i];
}
int readarray(int **array, char * filename)
{
FILE *f = fopen(filename, "r");
int n;
fscanf(f, "%d", &n);
//Lets allocate memory for n elements
*array = (int*)malloc(n * sizeof(int));
for(int i = 0; i < n; i++)
{
fscanf(f, "%d", (*array)+i);//&((*array)[i]) is also correct
}
fclose(f);
return n;
}
int main(int argc, char* argv[])//run using ./a.out input
{
int *array;
if(argc < 2)
{
printf("Please enter input filename\n");
return 0;
}
int size = readarray(&array, argv[1]);//Passing &array to get the dynamically created array adress to array pointer
printf("Read array is: \n");
printarray(array, size);
int *copy = copyandcreatearray(array, size);
printf("Bubblesorting...\n");
bubblesort(array, size);
printarray(array, size);
copyarray(copy, array, size);
printf("Selectionsorting...\n");
selectionsort(array, size);
printarray(array, size);
copyarray(copy, array, size);
printf("Insertionsorting...\n");
insertionsort(array, size);
printarray(array, size);
copyarray(copy, array, size);
printf("Quicksorting...\n");
quicksort(array, size);
printarray(array, size);
copyarray(copy, array, size);
printf("Heapsorting...\n");
heapsort(array, size);
printarray(array, size);
copyarray(copy, array, size);
printf("Mergesorting...\n");
mergesort(array, size);
printarray(array, size);

return 0;
}