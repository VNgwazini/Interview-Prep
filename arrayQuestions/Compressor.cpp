//Given a string with repeating characters, compress
// the string down to the chracter followed by the number of time it appears in the string 
//aaabb becomes a3b2

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string compressor(std::string &str){
  std::string result;
  std::vector<char> order;
  std::map<char,int> visited;

  //walk through and count frequency
  for(auto &it : str){
    if(visited[it]){
      visited[it]++;
    }
    else{
      order.push_back(it);
      visited[it]++;
    }
  }

  //build result string
  for(int i = 0; i < order.size(); i++){
    result.push_back(order[i]);
    //result.append(std::to_string( visited[ order[i] ] ) );
    //pass map interger value as its ascii character equivalent 
    result.push_back(visited[order[i]] +'0');
  }
  if(result.length() < str.length()){
    return result;
  }
  else{
    return str;
  }
}

int main(){
  std::vector<std::string> myStrings;
  myStrings.push_back("aaabb");
  myStrings.push_back("aabb");
  myStrings.push_back("ab");
  myStrings.push_back("abc");
  myStrings.push_back("zzz");

  for(auto &it : myStrings){
    try{
      throw compressor(it);
    }
    catch(std::string result){
      std::cout << result << std::endl;
    }
  }

}