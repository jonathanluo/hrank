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

/*
	http://www.cplusplus.com/forum/beginner/158390/
	auto it = std::lower_bound(v.begin(), v.end(), num);
	if(it == v.end() || *it != num) {
	    std::cout << num << " not found\n"
	} else {
	    std::size_t index = std::distance(v.begin(), it)
	    std::cout << num << " was found at " << index << '\n';
	    std::cout << "Replacing with 0";
	    *it = 0; // v[index] = 0
	}
*/
/**
 * https://stackoverflow.com/questions/27431029/binary-search-with-returned-index-in-stl
 *
 * @param v - sorted vector instance
 * @param data - value to search
 * @return 0-based index if data found, -1 otherwise
*/
int binary_search_find_index(std::vector<int> v, int data) {
    auto it = std::lower_bound(v.begin(), v.end(), data);
    if (it == v.end() || *it != data) {
        return -1;
    } else {
        std::size_t index = std::distance(v.begin(), it);
        return index;
    }   
}

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
    	} else if (type == 2) { // "2 v" - Delete the element from the heap
    		cin >> data;
    		
    		std::sort (v.begin(), v.end());
    		std::vector<int>::iterator low;
  			int index = binary_search_find_index(v, data);
  			if (index != -1) {
	  			std::swap(v[index], v[v.size() - 1]);
	  			v.pop_back();
  			}
    	} else if (type == 3) { // "3" - Print the minimum of all the elements in the heap
    		std::make_heap(v.begin(), v.end(), greater_func());
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