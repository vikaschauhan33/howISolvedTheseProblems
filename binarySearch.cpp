//Binary Search
/*
*  This method will return the index of the integer value 'val'
*  If the value is not present it will return -1.
*  Binary Search works on sorted values only
*  Time complexity is O(log N)
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& inp, int k){
  int low = 0;
  int high = inp.size() - 1;//High index is one less than the size of the vector
  while(low <= high){
    int mid = low + (high - low) / 2; // To avoid overflow.
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

  //Adding few test cases
  //Value is present
  assert(4 == binarySearch(v, valToFind));
  cout << "Test : Search present value -> passed.\n";

  //Searching for a value which is not present
  valToFind = 2005;
  assert(-1 == binarySearch(v, valToFind));
  cout << "Test : Search a value which is not present -> passed.\n";

  //Passing an empty vector
  std::vector<int> vEmp;
  assert(-1 == binarySearch(vEmp, valToFind));
  cout << "Test : Empty input vector -> passed.\n";

}
