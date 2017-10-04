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
    Professor (string name, int age, int cur_id) : Person(name, age), cur_id(cur_id) {
    }
    void getdata() {
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
    int n;
    cin >> n;
    int professor_id = 1;
    int student_id = 1;
    while (n-- > 0) {
        int type;
        string name;
        int age;
        cin >> type;
        cin >> name;
        cin >> age;
        if (type == 1) {
            Person* p = new Professor(name, age, professor_id++);
            p->getdata();
            p->putdata();
        } else {
            Person* p = new Student(name, age, student_id++);
            p->getdata();
            p->putdata();
        }
    }
    return 0;
}
