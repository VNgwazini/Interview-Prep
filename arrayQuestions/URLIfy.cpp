//Replace all the spaces in a string with the ASCII sybmol for space '%20'

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>

std::string urlIfy(std::string &str){
  //remove leading spaces
  std::size_t endPos = str.find_first_not_of(' ');
  if(endPos != std::string::npos){
    if(str[0] == ' '){
      str.erase(0,endPos);
    }
  }
  //remove trailing spaces
  std::size_t startPos = str.find_last_not_of(' ');
  if(startPos != std::string::npos){
    str.erase(startPos+1);
  }

  //count number of spaces
  int numSpaces = 0;
  for(auto &it : str){
    if(it == ' '){
      numSpaces++;
    }
  }
  //derive size of result string
  std::string result(str.size()+(numSpaces*2), ' ');
  int resultItr = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[i] != ' '){
      result[resultItr] = str[i];
      resultItr++;
    }
    else{
      result[resultItr] = '%';
      result[resultItr+1] = '2';
      result[resultItr+2] = '0';
      resultItr += 3;
    }
  }
  return result;
}

int main(){
  std::vector<std::string> myStrings;
  myStrings.push_back("My Home Page    ");
  myStrings.push_back("     Hello World, I'm Alive!   ");
  myStrings.push_back(" We're not in kansas anymore...   ");
  
  //auto iterator for standard collections
  for(auto &it : myStrings){
    std::cout << "[" << it << "]" << std::endl;
    std::cout << "[" << urlIfy(it) << "]\n" << std::endl;
  }
}