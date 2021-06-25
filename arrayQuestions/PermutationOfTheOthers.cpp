// Given two strings, check if one is a permutiation of the other
// i.e cba is permutation of abc

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isPermutation(std::string &str1, std::string &str2){
  if(str1.size() != str2.size()){
    return false;
  }

  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());

  for(int i = 0; i < str1.size(); i++){
    if(str1[i] != str2[i]){
      return false;
    }
  }
  return true;
}

int main(){
  std::vector<std::string> myStrings;
  myStrings.push_back("abc");
  myStrings.push_back("cba");
  myStrings.push_back("xyz");
  myStrings.push_back("abcdefghijklmnopqrstuvwxyz");

  for(int i = 1; i < myStrings.size(); i++){
    try{
      throw isPermutation(myStrings[0], myStrings[i]);
    }
    catch(bool result){
      if(result){
        std::cout << myStrings[i] << " IS permutation of " << myStrings[0] << "\n";
      }
      else{
        std::cout << myStrings[i] << " IS NOT permutation of " << myStrings[0] << "\n";
      }
    }
  }
}