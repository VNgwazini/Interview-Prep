//represent two numbers in linkedlist nodes and add the two then return the sum as a linkedlist
//i.e 8->2->5 + 4->9->2 is 528 + 294
//return 2->2->8 which a 822

//feed each list into a string digit by digit in reverse order
//convert strings to integer
//calculate sum
//convert sum to string then
//then push digits to list;

#include <iostream>
#include <string>
#include <cstring> //string conversions
#include <list> //linkedList
#include <sstream>

std::list<int> sumLists(std::list<int> &a, std::list<int> &b){
  std::list<int> sumList;
  
  //flip order
  std::list<int> stackA;
  for(auto &it : a){
    stackA.push_front(it);
  }

  //flip order
  std::list<int> stackB;
  for(auto &it : b){
    stackB.push_front(it);
  }

  //convert digits to string
  std::string strA;
  for(auto &it : stackA){
    strA.push_back(it);
  }
  std::string strB;
  for(auto &it : stackB){
    strB.push_back(it);
  }

  //convert string to single integer
  std::stringstream sstreamA(strA);
  std::stringstream sstreamB(strB);
  int aInt = 0, bInt = 0, sumInt = 0;
  sstreamA >> aInt;
  sstreamB >> bInt;
  //calculate sum
  sumInt = aInt + bInt;
  //convert sum to string
  std::string sumStr = std::to_string(sumInt);
  //convert string to list
  for(auto &it : sumStr){
    sumList.push_front(it);
  }
  
  return sumList;
}

int main(){
  std::list<int> list1;
  list1.push_front(5+'0');
  list1.push_front(2+'0');
  list1.push_front(8+'0');

  std::list<int> list2;
  list2.push_front(2+'0');
  list2.push_front(9+'0');
  list2.push_front(4+'0');

  std::cout << "(";
  for(auto &it : list1){
    std::cout << char(it) << "->";
  }
  std::cout << ") + (";

    for(auto &it : list2){
    std::cout << char(it) << "->";
  }

  std::cout << ") = ";


  std::list<int> result = sumLists(list1, list2);
  std::cout << "(";
  for(auto &it : result){
    std::cout << char(it) << "->";
  }
  std::cout << ")";
  std::cout << std::endl;
}