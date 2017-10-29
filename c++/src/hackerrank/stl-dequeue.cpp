/*
 * https://www.hackerrank.com/challenges/deque-stl/problem
 * 10/12/17
 */
 
#include <iostream>
#include <deque> 

using namespace std;

/*
 * n - number of items
 * k - k elements for one queue
 */
void printKMax(int arr[], int n, int k){
	//Write your code here.
	deque<int> d;
	for (int i = 0; i < n; i++) {
		d.push_back(arr[i]);
	}
}

int main() {  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
		cin >> n >> k;
		int i;
		int arr[n];
		for(i=0;i<n;i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}
 
/*
Sample Input
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

Sample Output
4 6 6 4
8 8 8 10
*/