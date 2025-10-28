#include <iostream>
#include "lib_myclass.h"

using namespace std;

int main(){

    MyClass<int> obj1(10);
    MyClass<char> obj2('A');
    MyClass<bool> obj3(true);

    cout<<"--- Integer value for MyClass ---"<<endl;
    cout<<obj1.get_value();
    obj1.set_value(20);
    cout<<"\n"<<obj1.get_value()<<endl;

    cout<<"--- Char value for MyClass ---"<<endl;
    cout<<obj2.get_value();
    obj2.set_value(68);
    cout<<"\n"<<obj2.get_value()<<endl;

    cout<<"--- Bool value for MyClass ---"<<endl;
    cout<<obj3.get_value();
    obj3.set_value(false);
    cout<<"\n"<<obj3.get_value()<<endl;

    return 0;
}

