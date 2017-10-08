/*
 * https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
 * 10/07/17
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* prev;
   Node* next;
   int key;
   int value;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   // head and tail is the cache data structure
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   public:
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
// http://www.cplusplus.com/reference/map/map/find/
class LRUCache : public Cache {
    public:
    LRUCache(int c) {
        cp = c;
    };
    virtual void set(int key, int value);
    virtual int get(int);
};

void LRUCache::set(int key, int value) {
    std::map<int, Node*>::iterator it;
    it = mp.find(key);
    if (it != mp.end()) { // found
        return; // does nothing, no duplicate keys allowed
    }
    Node* node = new Node(key, value);
    if (head == NULL) { // insert the first node
        head = node;
        tail = node;
        mp.insert(std::pair<int, Node*>(key, node));
        return;
    }
    // add at the tail
    tail->next = node;
    tail = node;
    mp.insert(std::pair<int, Node*>(key, node));
}

int LRUCache::get(int key) {
    std::map<int, Node*>::iterator it;
    it = mp.find(key);
    if (it != mp.end()) { // found
        std::pair<int, Node*> pair = *it;
        return pair.second->value; 
    } else {
        return -1;
    }
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
