/**
 * https://www.hackerrank.com/challenges/qheap1/problem
 */

#include<bits/stdc++.h>
using namespace std;

#define N 100000 //Heap size

struct minHeap {
    int n;
    int arr[N+1]; //array is 1 based
    minHeap(){ n=0 ;}
    void min_heapify(int index);
    void insert(int k);
    int search(int k);
    void deleteVal(int k);
    int getMin();
    int getRoot();
};
void minHeap::min_heapify(int i){
    int l = 2*i;
    int r = 2*i+1;
    int min = i;
    if(l<n && arr[l]<arr[min])
        min = l;
    if(r<n && arr[r]<arr[min])
        min = r;
    if(min != i){
        swap(arr[i],arr[min]);
        min_heapify(min);
    }
}
void minHeap::insert(int k){
    if(n==N) return;
    n++;
    arr[n]= k;
    int p= n;
    while(p>1){
        int pr= p/2;
        if(arr[pr]>arr[p]){
            swap(arr[pr],arr[p]);
            p= pr;
        }
        else break;
    }
}
int minHeap::getRoot(){
    if (n==0) 
    	return -1;
    else 
    	return arr[1];
}
int minHeap::getMin(){
	return getRoot();
}

int minHeap::search(int val){
    for(int i=1; i<=n; i++){
        if(arr[i] == val)
            return i;
    }
    return -1;
}

void minHeap::deleteVal(int val){
    int index = search(val);
    arr[index] = arr[n];
    n--;
    min_heapify(index);
}
  
int main(){
    minHeap h;
    int q, type, val;
    cin>>q;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>val;
            h.insert(val);
        }
        else if(type==2){
            cin>>val;
            h.deleteVal(val);
        }
        else{
            cout << h.getMin() << endl;
        }
    }
}
