//Binary Search
/*
*  This method will return the index of the integer value 'val'
*  if the value is not present it will return -1.
*  Binary Search works on sorted values only
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binarySearch(vector<int>& inp, int k){
  int low = 0;
  int high = inp.size();
  while(low <= high){
    int mid = low + (high -low)/2; // To avoid overflow.
    if(inp[mid] == k){
      return mid;
    } else if(inp[mid] > k){
        high = mid - 1;
    } else{ // inp[mid] < k
      low = mid + 1;
    }
  }
  return -1 ; // If the value is not present in the array;
}

int main (){
  std::vector<int> v{-1, -2, 5, 15, 205, 400}; //Taking sorted array for simplicity
  int valToFind = 205;
  //cout << binarySearch(v, valToFind);
  assert(4 == binarySearch(v, valToFind));
  cout << "Test 1 passed\n";
  valToFind = 2005;
  assert(-1 == binarySearch(v, valToFind));
  cout << "Test 2 passed\n";
}
