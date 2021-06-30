//write a method that removes any duplicates from out linkedList

//iterate through list
//on each node, 
//if we have not visited it before, then mark it as visited and continue
//if we have visited the node before, then remove that node;
#include <iostream>
#include <map>

struct Node{
  int key;
  char value;
  Node* next;
  Node(int key, char value){
    this->key = key;
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList{
  public:
    Node* head;
    LinkedList(){
      head = nullptr;
    }

    Node* insert(int key, char value){
      if(!head){
        return head = new Node(key, value);
      }
      else{
        Node* itr = head;
        while(itr){
          if(itr->next){
            itr = itr->next;
          }
          else{
            return itr->next = new Node(key, value);
          }
        }
      }
    }

    Node* remove(int key){
      if(!head){
        return nullptr;
      }
      if(head->key == key){
        Node* temp = head->next;
        delete head;
        return head = temp;
      }
      else{
        Node* itr = head;
        while(itr->next){
          if(itr->next->key == key){
            Node* temp = itr->next->next;
            delete itr->next;
            return itr->next = temp;
          }
          else{
            itr = itr->next;
          }
        }
      }
    }

    void print(){
      if(!head){
        return;
      }
      Node* itr = head;
      while(itr){
        std::cout << "(" << itr->key << ", " << itr->value << ")\t";
        itr = itr->next;
      }
      std::cout << std::endl;
    }

    //removes duplicates from list
    void duplicates(){
      if(!head){
        std::cout << "List Empty\n";
        return;
      }
      Node* itr = head;
      std::map<char, bool> visited;

      while(itr){
        //reached duplicate
        if(visited[itr->value]){
          remove(itr->key);
          itr = itr->next;
        }
        //not duplicate
        else{
          visited[itr->value] = true;
          itr = itr->next;
        }
      }
    }
};

int main(){
  LinkedList list;
  list.insert(1, 'a');
  list.insert(2, 'b');
  list.insert(3, 'a');
  list.print();
  list.duplicates();
  list.print();
}