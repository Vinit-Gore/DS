void buildmaxheap(int [], int);
void maxheapify(int [], int, int);

void heapsort(int array[], int size){
    int heapsize = size, swaps=0;
    buildmaxheap(array,heapsize);
    for(int i=heapsize-1;i>0;i--){
        swap(&array[0],&array[heapsize-1]);
        swaps++;
        heapsize--;
        maxheapify(array,heapsize, 0);
    }
    
}

void buildmaxheap(int array[], int heapsize){
    for(int i=heapsize/2; i>=0;i--)
    maxheapify(array, heapsize, i);
}

void maxheapify(int array[], int heapsize, int index){
    int l = 2*index+1, r = 2*index +2, largest=index;
    if(l<heapsize) {
        if (array[l]>array[index]) largest = l; 
        else largest = index;
        }
    if(r<heapsize) {
        if(array[r]>array[largest])  largest = r; 
        }

    if(largest != index)   {
     swap(&array[index], &array[largest]);
    maxheapify(array, heapsize, largest);

    }
    }
