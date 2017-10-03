/*
    https://www.hackerrank.com/challenges/virtual-functions/problem
    
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
    int publications;
    int cur_id;
public:
    Professor (string name, int age, int publications, int cur_id) : Person(name, age), publications(publications), cur_id(cur_id) {
    }
    void getdata() {
        Person::getdata();
        cin >> publications;
    }
    void putdata() {
        printf("%s %d %d %d\n", name.c_str(), age, publications, cur_id);
    }
    
};

class Student : public Person {
    int marks[6];
    int cur_id;
public:
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

int main() {
    return 0;
}
