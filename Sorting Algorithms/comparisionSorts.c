#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection(long a[], long n);
void bubble(long a[], long n);
void insertion(long a[], long n);
void mergesort(long a[], long left, long right);
void quicksort(long a[], long left, long right);
void heapsort(long a[], long n);

//A heap has a current size and array of elements
struct MaxHeap{
  long size;
  long* array;
};
typedef struct MaxHeap maxHeap;
void main(){
  long arr[100000];
  long n=100000;
  int i,j;
  /*Initialise the array*/
  for(i=0;i<n;i++){
    arr[i] = rand();
  }
  /*print input non-sorted array
  for(i=0;i<n;i++){
    printf("%ld\n",arr[i]);
  }*/

  /*start timer*/
  clock_t s,e;
  s = clock();

  /*start sorting*/
  heapsort(arr,n);
  /*end sorting*/

  e = clock();
  /*end timer*/

  printf("Time Taken : %f seconds\n",(double)(e-s)/CLOCKS_PER_SEC);

  /*print output
  for(i=0;i<n;i++){
    printf("%ld\n",arr[i]);
  }*/
}
void swap(long* x, long* y){

  long temp;
  temp = *x;
  *x = *y;
  *y = temp;

}
void selection(long a[], long n){
  int i,j,k,l;
  for(i=0;i<n;i++){
    k = i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[k]){
        k = j;
      }
    }
    swap(&a[i], &a[k]);
  }
}

void bubble(long a[], long n){
  int i,j,swapped=0;
  for(i=0;i<n;i++){
    swapped=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        swap(&a[j], &a[j-1]);
        swapped=1;
      }
    }
    if(swapped==0){
      break;
    }
  }
}
void insertion(long a[], long n){
  int i,j;
  for(i=1;i<n;i++){
    for(j=i;j>0 && a[j]<a[j-1];j--){
      swap(&a[j],&a[j-1]);
    }
  }
}
/*merge function for mergesort */
void merge(long a[], long left, long middle, long right){
  long i, j, k;
  long n1 = middle-left+1;
  long n2 = right-middle;

  /*temp arrays*/
  long L[n1],R[n2];

  /* copy data to temp arrays */
  for(i=0;i<n1;i++){
    L[i] = a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = a[middle+1+i];
  }

  /*merge the two temp arrays back*/
  i=0;
  j=0;
  k=left;
  while(i<n1 && j<n2){
    a[k++] = (L[i]<=R[j])?L[i++]:R[j++];
  }
  /*copy the remaining elements of L[] if any*/
  while(i<n1){
    a[k++]=L[i++];
  }
  /*copy the remaining elements of R[] if any*/
  while(j<n2){
    a[k++]=R[j++];
  }
}

void mergesort(long a[], long left, long right){
  if(left < right){
    //split in half
    long middle = (left + right)/2 ;

    //recursive sorts
    mergesort(a, left, middle);
    mergesort(a, middle+1, right);

    //function : merge sorted sub-arrays using temporary array

    /*perform merging*/
    merge(a, left, middle, right);
  }
}

/*partition for quick sort left most element is pivot*/
long partition(long a[], long left, long right){
  long x = a[right]; //pivot
  long i = (left-1); //index of a smaller element
  long j;
  for(j=left;j<right;j++){
    if(a[j]<=x){
      i++; //increment index of smaller element
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i+1],&a[right]);
  return (i+1);
}

/* pivot is leftmost element */
void quicksort(long a[], long left, long right){
  if(left < right){
    long p = partition(a, left, right);
    quicksort(a, left, p-1);
    quicksort(a, p+1, right);
  }
}

//heapify function, works on max heap
void heapify(maxHeap* heap, long idx){
  long largest = idx;
  long left = (idx<<1)+1; //2i + 1
  long right = (idx+1)<<1; // 2* (i + 1) = 2i + 2

  //for left child
  if(left<heap->size && heap->array[left] > heap->array[largest]){
    largest = left;
  }

  //for right child
  if(right<heap->size && heap->array[right] > heap->array[largest]){
    largest = right;
  }

  //change root, if needed
  if(largest!=idx){
    swap(&heap->array[largest], &heap->array[idx]);
    heapify(heap, largest);
  }
}
maxHeap* createAndBuildHeap(long* array, long size){
  long i;
  maxHeap* heap = (maxHeap*) malloc(sizeof(maxHeap));
  heap->size = size; //initialize the size of the array
  heap->array = array; //Assign address of first element of array to be sorted

  //bottom-top heapification
  for(i=(heap->size-2)/2;i>=0;--i){
    heapify(heap,i);
  }
  return heap;
}

void heapsort(long a[], long n){
  //build heap from input
  maxHeap* heap = createAndBuildHeap(a, n);

  while(heap->size>1){
    swap(&heap->array[0], &heap->array[heap->size - 1]);
    --heap->size;
    //finally heapify the root
    heapify(heap,0);
  }
}
