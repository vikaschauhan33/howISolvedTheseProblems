/*
* This method is to find all the anagrams in a given dictionary
* Anagram examples "scrabble" and "clabbers" or "car" and "arc".
* Assuming that Tar and art are anagrams i.e. Case insensitive.
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> findAllAnagramsInADictionary(const vector<string>& dictionary) {
  unordered_map<string, vector<string>> mapAnagrams;

  for(auto str : dictionary){
    //Change to lower case
    std::transform(str.begin(), str.end(),str.begin(), ::tolower);

    string sort_string(str);
    
    //All the anagrams will have same characters
    sort(begin(sort_string),end(sort_string));
    mapAnagrams[sort_string].emplace_back(str);
  }

  vector<vector<string>> res;
  for(const auto& x : mapAnagrams){
    //String with same hash code
    if(x.second.size() >= 2){
      res.emplace_back(x.second);
    }
  }
  return res;
}


int main(){
  vector<string> dict {"car", "rat", "late", "guitar", "scrabble", "no", "Not",
                      "rac", "tar", "art", "arc", "tale", "clabbers", "on", "ton"};

  assert( 6 == findAllAnagramsInADictionary(dict).size());
  cout<< "Test 1 : Passed \n";
  for(const auto& vec : findAllAnagramsInADictionary(dict)){
    cout << '\n';
    for(const auto& v : vec){
      cout << v << " : " ;
    }
  }
}
