#include <iostream>

using namespace std;

// generic function overloading
template <class X> void interchange(X &a, X &b){
    X temp;
    temp = a;
    a = b;
    b = temp;
}

// specific function 
void interchange(int &a, int &b){
    int temp;
    temp = a;
    a = b*10;
    b = temp*10;
}

int main(){
    double x = 3.14, y = 2.71;
    int m = 11, n = 35;
    
    cout<<"Interchange "<<x<<" and "<<y<<": "<<endl;
    interchange(x, y);
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    
    cout<<"Interchange "<<m<<" and "<<n<<": "<<endl;
    interchange(m, n);
    cout<<"m = "<<m<<endl;
    cout<<"n = "<<n<<endl;
    
    return 0;
}
