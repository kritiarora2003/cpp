#include <stdio.h>
#include <stdlib.h>

// Structure of a heap
struct heap {
    int *arr;
    int heap_size;  // size of the array
    int max_size;   // total size allowed
};

// List of functions below
void swap(int *a, int *b);
struct heap* makeMinHeap(int* arr, int n, int max_size);
void insert_minHeap(struct heap* h, int data);
int delete_minHeap(struct heap* h);
void minHeapify(struct heap* h, int index);
void print_heap(struct heap* h);
void heapsort(struct heap* h);

// Swap function
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function which takes an array and converts it into a heap array
struct heap* makeMinHeap(int* arr, int n, int max_size){

    // max_size is the max size allowed for a heap
    // n is size of the input array

    // heap ko jaga do
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    
    // size 0 karo, max memory me max memory karo
    h->heap_size = n;
    h->max_size = max_size;

    // heap ki array ko jaga do
    h->arr = (int*)malloc(sizeof(int) * max_size);

    // array me jumbled number fit karo
    int i;
    for(i = 0; i < n; i++){
        h->arr[i] = arr[i];
    }

    // array ko heap me convert karo
    i = n;
    // leaves saare chhotu chhotu heap hi toh hain
    i = (i-2) / 2;
    while(i >= 0){
        minHeapify(h, i);
        i--;
    }

    return h;
}

// Function to insert in a heap
void insert_minHeap(struct heap* h, int data){

    // last me data bharo
    h->arr[h->heap_size] = data;

    // aage ki jaga badao
    h->heap_size = h->heap_size+1;

    // neeche wale ko apni jagah pe le jao
    int change = h->heap_size-1;
    while(change > 0){
        int parent = (change - 1)/2;
        if(h->arr[parent] > h->arr[change]){
            swap(&(h->arr[parent]), &(h->arr[change]));
            change = parent;
        }
        else
        break;
    }
}

// Function to delete the top element from a heap
int delete_minHeap(struct heap* h){
    int min;
    if(h->heap_size == 0){
        printf("Heap is empty\n");
        return -1;
    }

    // min acquired
    min = h->arr[0];

    // last element to first place
    h->arr[0] = h->arr[h->heap_size - 1];
    h->heap_size--;

    // now heapify
    minHeapify(h,0);

    return min;
}

// Function which heapifies elements after index
void minHeapify(struct heap* h, int index){
    int left = 2*index +1;
    int right = 2*index + 2;
    int min = index;

    // finding min
    if(h->arr[left] < h->arr[min] && left < h->heap_size){
        min = left;
    }
    
    if(h->arr[right] < h->arr[min] && right < h->heap_size){
        min = right;
    }

    // if min == index then return (this is base case)
    // if not then where ever min is, make it a heap
    if(min != index){
        swap(&(h->arr[min]), &(h->arr[index]));
        minHeapify(h, min);
    }
}

// Prints the heap array
void print_heap(struct heap* h){
    for(int i = 0 ; i < h->heap_size; i++){
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}


int main(){
    int size = 11;
    int arr[] = {15,7,11,20,16,48,35,10,12,5,6};
    printf("Original unheapified array\n");
    for(int i = 0 ; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    struct heap* h = makeMinHeap(arr,size,15);
    printf("Heapified heap\n");
    print_heap(h);
    printf("\n");

    int n = 8;
    printf("Insert element %d\n", n);
    insert_minHeap(h,8);
    print_heap(h);
    printf("\n");

    printf("Delete first element\n");
    int min = delete_minHeap(h);
    print_heap(h);
    printf("\n");
}