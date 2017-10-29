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

// #include<bits/stdc++.h> // http://www.geeksforgeeks.org/bitsstdc-h-c/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 18.52 points, max: 25
 * 10/19/17
 */

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
    //std::vector<int> v(N);
    //cout<< v.size() << endl;
    int n, sweetness;
    cin >> n;
    cin >> sweetness;
    while (n-- > 0) {
		int data;
		cin >> data;
		v.push_back(data);
	}
	std::make_heap(v.begin(), v.end(), greater_func());
	int count = 0;
	while (true) {
		if (v.front() > sweetness) {
			break;
		}
		int cookie1 = v.front();
		std::pop_heap (v.begin(),v.end(), greater_func()); v.pop_back();

		int cookie2 = v.front();
		std::pop_heap (v.begin(),v.end(), greater_func()); v.pop_back();

		int newcookie = 1 * cookie1 + 2 * cookie2;
		v.push_back(newcookie);
		std::push_heap(v.begin(), v.end(), greater_func());
		count++;
	}
	cout << count << endl;
    return 0;
}

/*
input:
6 7
1 2 3 9 10 12

output:
2
*/
