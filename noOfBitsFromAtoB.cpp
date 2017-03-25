/*
*  Method to find number of bits needed to convert
*  A to B
*/

#include <iostream>
#include <cassert>

using namespace std;

int noOfBitsToConvertAtoB(int a, int b){
  int count = 0;
  for(int c = a ^ b; c != 0 ; c = c>>1){
     count += c & 1;
  }
  return count;
}

int main(){
  int a = 3;
  int b = 5;

  assert(2 == noOfBitsToConvertAtoB(a, b));
  cout <<"Test1 : Passed for 3 and 5";
}
