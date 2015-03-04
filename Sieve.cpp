#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
/**
Sieve of Eratosthenes :
Use to find all prime numbers efficiently for numbers upto 10million = 10000000
*/

void markMultiples(bool a[], int start, int size){
  int i=2, j;
  while((j=i*start)<=size){
    a[j-1]=1; //not prime mark it as true
    i++;
  }
}
void Sieve(int n){
  if(n >= 2){
    bool a[n];
    memset(a, 0, sizeof(a)); //set all false initially which implies all are prime

    for(int i=1; i<n ; i++){
      if(!a[i]){
        cout<<(i+1)<<" ";
        markMultiples(a, i+1, n); //mark multiples as true as they are not prime
      }
    }
  }
}
int main(){
  int n;
  cin>>n;
  Sieve(n);
  cout<<endl;
  return 0;
}
