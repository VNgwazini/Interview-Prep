#include <iostream>
#include <unordered_map>
#include <vector>
//Given a string, see if you can detect whether it contains only unique chars.
bool isUnique(std::string &str){
  std::unordered_map<char, bool> visited;
  for(int a = 0; a < str.size(); a++){
    if(visited[str[a]]){
      return false;
    }
    else{
      visited[str[a]] = true;
    }
  }
  return true;
}

int main(){
  std::vector<std::string> myStrings;
  myStrings.push_back("ab");
  myStrings.push_back("aa");
  myStrings.push_back("abcdefghijklmnopqrstuvwxyz");

      for(int i = 0; i < myStrings.size(); i++){
        try {
          throw isUnique(myStrings[i]);
        }  
        catch(bool result){
          if(result){
            std::cout <<  myStrings[i] << " is unique!\n";
          }
          else{
            std::cout <<  myStrings[i] << " is not unique!\n";
          }
        }
  }
}