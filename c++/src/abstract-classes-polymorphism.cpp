/*
 * https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
 * 10/07/17
 */
#include <iostream>
#include <cstdio>
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
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

// http://www.cplusplus.com/reference/map/map/find/
class LRUCache : public Cache {
    int count;
    public:
    LRUCache(int c) : count(0) {
        cp = c;
        head = NULL;
        tail = NULL;
    };
    virtual void set(int key, int value);
    virtual int get(int);
    void printCache();
};

void LRUCache::printCache() {
    Node* curr = head;
    while (curr != NULL) {
//    	printf("(%d, %d) ", curr->key, curr->value);
        curr = curr->next;
    }
}

void LRUCache::set(int key, int value) {
    std::map<int, Node*>::iterator it;
    it = mp.find(key);
    if (it != mp.end()) { // found
    	Node* curr = (*it).second;
    	curr->value = value;
        return; // replace with new value for the same key
    }
    Node* node = new Node(key, value);
    mp.insert(std::pair<int, Node*>(key, node));
}

int LRUCache::get(int key) {
    // lookup from cache first
    Node* curr = head;
    while (curr != NULL) {
        if (curr->key == key) {
            if (curr == head) {
                // key is the first one, does nothing
                return curr->value;
            } else if (curr == tail) {
            	if (curr->prev != NULL) {
					tail = curr->prev;
					tail->next = NULL;
            	}
                // move to the head
                curr->next = head->next;
                head = curr;
                head->prev = NULL;
            } else { // move recently used at head
                curr->prev->next = curr->next;
                curr->next = head->next;
                head = curr;
                head->prev = NULL;
            }
            return curr->value;
        }
        curr = curr->next;
    }
    // search from map
    std::map<int, Node*>::iterator it;
    it = mp.find(key);
    if (it == mp.end()) { // not found
        return -1;
    }
    std::pair<int, Node*> pair = *it;
    curr = pair.second;
    // add the node just found at the head
    // remove LRU from tail if capacity exceeded
    count++;
    if (head == NULL) { // insert the first node
        head = curr;
        tail = curr;
        head->next = NULL;
        head->prev = NULL;
    } else { // add at head
        curr->next = head;
        head->prev = curr;
        head = curr;
        head->prev = NULL;
        if (count > cp) {
            // rermove the LRU node at tail
        	if (tail->prev != NULL) {
				tail = tail->prev;
				tail->next = NULL;
        	} else {
        		tail = head;
        	}
            count = cp;
        }
    }
    return curr->value; 
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
         l.printCache();
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

/*
3 1
set 1 2
get 1
get 2

2
-1
-- =======================
4 1
set 1 2
set 2 7
get 1
get 2

2
-1
-- =======================
6 2
set 1 2
set 2 7
get 1
get 2
set 2 9
get 2


-- =======================
8 4
set 4 2
set 2 7
get 2
set 1 8
set 5 9
set 6 15
get 4
get 5

Expected output:
7
-1
9
*/
