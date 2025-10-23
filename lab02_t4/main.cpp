#include <iostream>
#include "lib_vector.h"
#include "lib_string.h"

using namespace std;

template <class X> void interchange(X &a, X &b){
    X temp;
    temp = a;
    a = b;
    b = temp;
}

void interchange(int &a, int &b){
    int temp;
    temp = a;
    a = b*10;
    b = temp*10;
}

int main(){

    int a = 10, b = -10;
    double x = 3.14, y = 2.71;
    Vector v1(1, 2), v2(-3, -4);
    MyString s1("OOP"), s2("C++");

    cout<<"-- Experiment 1 --"<<endl;
    interchange(a, b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    cout<<"-- Experiment 2 --"<<endl;
    interchange(x, y);
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;

    cout<<"-- Experiment 3 --"<<endl;
    interchange(v1, v2);
    cout<<"v1 = ";
    v1.print();
    cout<<"v2 = ";
    v2.print();
    
    cout<<"-- Experiment 4 --"<<endl;
    interchange(s1, s2);
    cout<<"s1 = ";
    cout<<s1.get_string()<<endl;
    cout<<"s2 = ";
    cout<<s2.get_string()<<endl;

    return 0;
}

