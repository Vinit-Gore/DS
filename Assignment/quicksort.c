void quick_sort(int [], int, int);
int partition(int [], int, int);

void quicksort(int array[], int size){
    int p=0, r= size-1, swaps = 0;
    quick_sort(array, p ,r);
}

void quick_sort(int array[], int p, int r){
    if(p<r){
       int q=partition(array,p,r);
        quick_sort(array, p, q-1);
        quick_sort(array, q+1, r);
    }
}

int partition(int array[], int p, int r){
    int pivot=array[p];
    int i=p;
    for(int j=p+1;j<=r;j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i],&array[p]);
    return i;
}