#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void countingsort(long a[], long n, long max);
void radixsort(long a[], long n, long max);
void bucketsort(long a[], long n);

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
  long max = 100000;
  for(i=0;i<n;i++){
    arr[i] = rand()%max;
  }
  /*print input non-sorted array
  for(i=0;i<n;i++){
    printf("%ld\n",arr[i]);
  }*/

  /*start timer*/
  clock_t s,e;
  s = clock();

  /*start sorting*/
  radixsort(arr,n,max);
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
//normal counting sort
void countingsort(long a[], long n, long max){
  long i,output[n],count[max];
  for(i=0;i<max;i++){
    count[i]=0;
  }
  //hash
  for(i=0;i<n;i++){
    ++count[a[i]];
  }
  //update
  for(i=1;i<max;i++){
    count[i] += count[i-1];
  }
  //output
  for(i=0;i<n;i++){
    output[count[a[i]]-1] = a[i];
    --count[a[i]];
  }
  //copy to main array
  for(i=0;i<n;i++){
    a[i]=output[i];
  }
}

//counting sort for radix sort
void crsort(long a[], long n, long exponent){
  long max=10;
  long i,output[n],count[max];
  for(i=0;i<max;i++){
    count[i]=0;
  }
  //hash
  for(i=0;i<n;i++){
    ++count[(a[i]/exponent)%10];
  }
  //update
  for(i=1;i<max;i++){
    count[i] += count[i-1];
  }
  //output
  for(i=n-1;i>=0;i--){
    output[count[(a[i]/exponent)%10]-1] = a[i];
    count[(a[i]/exponent)%10]--;
  }
  //copy to main array
  for(i=0;i<n;i++){
    a[i]=output[i];
  }
}
void radixsort(long a[], long n, long max){
  long exponent;
  for(exponent=1;max/exponent > 0; exponent*=10){
    crsort(a,n,exponent);
  }
}
