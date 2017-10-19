/**
 * https://www.hackerrank.com/challenges/qheap1/problem
 * http://www.geeksforgeeks.org/stdmake_heap-c-stl/
 *
 * https://stackoverflow.com/questions/7681779/easy-way-to-maintain-a-min-heap-with-stl
 * If you want to create a min heap. The quickest way to do that is to use make_heap algorithm. 
 * However, that creates a max heap by default
 *
 * A becomes a max heap. To have a min heap, on the other hand, you need to add a comparator 
 * but do not need to implement one. Instead call the method as follows:
 * make_heap(A.begin(), A.end(), greater<int>());
 */
 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// http://www.sanfoundry.com/cpp-program-create-heap-using-make_heap-operation/
void print(const std::vector <int>& v) {
    std::vector <int>::const_iterator i;
    for(i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

// https://stackoverflow.com/questions/14016921/comparator-for-min-heap-in-c
struct greater_func { // use greater function to make a min heap
  bool operator()(const long& a,const long& b) const{
    return a>b;
  }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::vector<int> v;
    int n;
    cin >> n;
    while (n-- > 0) {
    	int type;
		int data;
    	cin >> type;
    	if (type == 1) { // "1 v" - Add an element to the heap
    		cin >> data;
    		v.push_back(data);
    		std::make_heap(v.begin(), v.end(), greater_func());
    	} else if (type == 2) { // "2 v" - Delete the element from the heap
    		cin >> data;
    		int size = v.size();
    		while (size-- > 0) {    	
	    		std::pop_heap(v.begin(), v.end(), greater_func()); // pop action moves the "root" to the end of vector 
	    		if (data == v[v.size() - 1]) {
	    			v.pop_back(); // remove the data
	    		}
    		}
    	} else if (type == 3) { // "3" - Print the minimum of all the elements in the heap
    		cout << v.front() << endl;
    	}
    }
    return 0;
}
/*
5
1 4  
1 9  
3
2 4  
3

*/