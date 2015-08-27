#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  string str;
  cin>>str;
  int flag=0;
  while(str.length()){
    if(str != string(str.rbegin(), str.rend())){
      flag = 1;
      break;
    }
    str.erase(str.begin());
  }
  if(flag)
    cout<<str.length()<<endl;
  else
    cout<<"0"<<endl;

}