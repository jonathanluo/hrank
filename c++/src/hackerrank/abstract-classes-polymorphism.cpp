/*
 * https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
 * 10/07/17 Points: 314 Rank: 10230
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
    int count; // cache item count
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

/*
set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key.
	    If the cache has reached its capacity, it should replace the least recently used key with a new key.
*/
void LRUCache::set(int key, int value) {
    std::map<int, Node*>::iterator it;
    it = mp.find(key);
    if (it != mp.end()) { // found
    	Node* curr = (*it).second;
    	curr->value = value;
        return; // replace with new value for the same key, no cacahe update is needed
    }
    // add to the map first
    Node* node = new Node(key, value);
    mp.insert(std::pair<int, Node*>(key, node));
    // add to the head of the cache
    count++;
    Node* curr = node;
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
    }
    if (count > cp) {
        // remove the LRU node at tail
    	if (tail->prev != NULL) {
			tail = tail->prev;
			tail->next = NULL;
    	} else {
    		tail = head;
    	}
        count = cp;
    }
}
/**
 * get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 */
int LRUCache::get(int key) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->key == key) {
			return curr->value;
        }
        curr = curr->next;
    }
    return -1;
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

Expected output:
2
-1
-- =======================
4 1
set 1 2
set 2 7
get 1
get 2

Expected output:
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

Expected output:
2
7
9
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
