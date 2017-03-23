/*
* This method searches for the firs occurance of the 'val'
* is a given sorted array.
* Sorted array can have duplicate values.
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int firstOccuraceOfK(const vector<int>& inp,
                      int k){
  int low = 0, high = inp.size() - 1, index = -1;

  while(low <= high){
    int mid = low + (high - low)/2;
    if(inp[mid] == k){
      index = mid;
      high  = mid -1;
    } else if (inp[mid] > k){
       high = mid - 1;
    } else {
        low = mid + 1;
    }
  }
  return index;
  }

int main (){
  std::vector<int> v{-1, -2, 5, 5, 15, 205, 400, 400}; //Taking sorted array for simplicity
  int valToFind = 205;

  //Adding few test cases
  //Value is present
  assert(5 == firstOccuraceOfK(v, valToFind));
  cout << "Test 1 : Search present value -> passed.\n";

  //Searching for a value which is not present
  valToFind = 2005;
  assert(-1 == firstOccuraceOfK(v, valToFind));
  cout << "Test 2 : Search a value which is not present -> passed.\n";

  //Passing an empty vector
  std::vector<int> vEmp;
  assert(-1 == firstOccuraceOfK(vEmp, valToFind));
  cout << "Test 3 : Empty input vector -> passed.\n";

  //Searching for a duplicate value
  valToFind = 5;
  assert(2 == firstOccuraceOfK(v, valToFind));
  cout << "Test 4 : Search a duplicate value -> passed.\n";

  //Searching for a duplicate value
  valToFind = 400;
  assert(6 == firstOccuraceOfK(v, valToFind));
  cout << "Test 5 : Search a duplicate value -> passed.\n";

}
