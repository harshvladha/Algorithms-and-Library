#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*merge function for mergesort */
long long merge(long long a[],  long long left,  long long middle,  long long right){
  long long i, j, k, count=0;
  long long n1 = middle-left+1;
  long long n2 = right-middle;

  /*temp arrays*/
  long long L[n1],R[n2];

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
  	if(L[i]<=R[j])
  		a[k++]=L[i++];
  	else{
  		a[k++]=R[j++];
  		count+=n1-i;
  	}
  }
  /*copy the remaining elements of L[] if any*/
  while(i<n1){
    a[k++]=L[i++];
  }
  /*copy the remaining elements of R[] if any*/
  while(j<n2){
    a[k++]=R[j++];
  }
  return count;
}

long long mergesort( long long a[],  long long left,  long long right){
	long long count=0;
  if(left < right){
    //split in half
    long long middle = (left + right)/2 ;

    //recursive sorts
    count = mergesort(a, left, middle);
    count += mergesort(a, middle+1, right);

    /*perform merging*/
    count += merge(a, left, middle, right);
  }
  return count;
}

int main() {
    long long t;
    cin>>t;
    while(t--){
    	long long N;
    	cin>>N;
    	long long a[N];
    for(long long i=0;i<N;i++){
    	cin>>a[i];
    }
    cout<<mergesort(a,0, N-1)<<endl;
    }
    return 0;
}
