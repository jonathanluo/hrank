#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// https://www.hackerrank.com/challenges/c-class-templates/problem
// https://www.geeksforgeeks.org/template-specialization-c/
// https://www.cprogramming.com/tutorial/template_specialization.html

#include <iostream>
using namespace std;

template <class T>
class AddElements {
  T first;
  public:
    AddElements (T first) {
        this->first = first;
    }
    T add (T second) {
      return (first + second);
    }
};


// class template specialization:
template <>
class AddElements <string> {
    string first; 

    public:
    AddElements (string first) {
        this->first = first;
    }
    string concatenate (string second) {
        return first + second;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
