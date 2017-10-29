/*
    https://www.hackerrank.com/challenges/virtual-functions/problem
    Points: 140 Rank: 28127 10/03/17
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person () {
    }
    Person (string name, int age) : name(name), age(age) {
    }

    virtual void getdata() {
        cin >> name;
        cin >> age;
    };

    virtual void putdata() {
        printf("%s %d\n", name.c_str(), age);
    };
};

class Professor : public Person {
    static int count;
    int publications;
    int cur_id;
public:
    Professor () {
        cur_id = ++Professor::count;
    }
    Professor (string name, int age, int cur_id) : Person(name, age), cur_id(cur_id) {
    }
    void getdata() {
        Person::getdata();
        cin >> publications;
    }
    void putdata() {
        printf("%s %d %d %d\n", name.c_str(), age, publications, cur_id);
    }

};

int Professor::count=0;

class Student : public Person {
    static int count;
    int marks[6];
    int cur_id;
public:
    Student () {
        cur_id = ++Student::count;
    }
    Student (string name, int age, int cur_id) : Person(name, age), cur_id(cur_id) {
    }
    void getdata() {
        Person::getdata();
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
    void putdata() {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        printf("%s %d %d %d\n", name.c_str(), age, sum, cur_id);
    }
};

int Student::count=0;

/*
Input:
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87

Output:
Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2
*/
int main() {

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){
        cin >> val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor();
        }
        else per[i] = new Student(); // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for(int i = 0; i< n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
