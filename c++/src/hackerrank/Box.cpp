#include <bits/stdc++.h>

using namespace std;

/**
 * https:www.hackerrank.com/challenges/box-it/problem
 * Points: 224 Rank: 16301 10/06/17
 */


class Box {

    int l,b,h;
public:

    Box() {
        l = 0;
        b = 0;
        h = 0;
    };
    Box(int l, int b, int h) : l(l), b(b), h(h) {};
    Box(const Box& b) {
        this->l = b.l;
        this->b = b.b;
        this->h = b.h;
    };

    int getLength() {
        return l;
    }
    int getBreadth () {
        return b;
    }
    int getHeight () {
        return h;
    }
    long CalculateVolume() {
        return l * b * h;
    }
    Box operator+(const Box& b);
    bool operator<(const Box& b);
    // https://stackoverflow.com/questions/476272/how-to-properly-overload-the-operator-for-an-ostream
    friend ostream& operator<<(ostream& out, const Box& b);

}; 

 // https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
Box Box::operator+(const Box& b) {
    Box box;
    box.l = this->l + b.l;
    box.b = this->b + b.b;
    box.h = this->h + b.h;
    return box;
}

bool Box::operator<(const Box& b) {
    if (this->l < b.l)
        return true;
    else if ((this->l == b.l) && (this->b < b.b))
        return true;
    else if ((this->l == b.l) && (this->b == b.b) && (this->h < b.h)) 
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Box& B) {
    out << B.l << " " << B.b << " " << B.h;
    return out;
}

void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}

/*
Input (stdin)
5
2 3 4 5
4
5
4
2 4 6 7

Expected Output
3 4 5
60
3 4 5
60
4 6 7
*/