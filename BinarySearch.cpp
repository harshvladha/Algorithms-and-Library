#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void BinarySearch(int a[], int key){
  int lo=0, hi=sizeof(a)/sizeof(a[0]) - 1;
  while(lo<=hi){
    int mid = lo + (hi-lo)/2 ;
    if(key<a[mid]) hi = mid-1;
    else if(key>a[mid]) lo = mid+1;
    else return mid;
  }
  return -1;
}
int main(){
	int a;
	return 0;
}

