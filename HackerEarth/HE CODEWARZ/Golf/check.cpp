#include <iostream>
using namespace std;
int main()
{
  //take solution output and count characters
  int count=0;
  char ch;
  while (scanf("%c",&ch)!=EOF)
    {
      //you can also validate char x to increment count in case you want to count only whitespace chars

      //here I am going to count all chars
      count++;
    }
    //apply fromula given in problem statement to calculate score based on soution size

    double score = 0.0;
    if (count<300)
      {
        score = 150*(300 - count)/300;
      }
      else{
        score = 150*0.0001;
      }
      cout<<score;

      return 0;
    }
