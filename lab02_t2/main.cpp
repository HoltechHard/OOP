#include <iostream>

using namespace std;

// generic function with multiple args
template <class X, class Y> void print(X arg1, Y arg2){
    cout<<"Arg 1: "<<arg1<<endl;
    cout<<"Arg 2: "<<arg2<<endl;
}

int main(){
    cout<<"-- Experiment 1 --"<<endl;
    print("Pi", 3.14);
    cout<<"-- Experiment 2 --"<<endl;
    print(true, 1);
    cout<<"-- Experiment 3 --"<<endl;
    print('A', "Apple");

    return 0;
}
