#include <iostream>

using namespace std;

// generalized function with 1 argument
template <class X> X AddOne(X arg){
    X result;
    result = arg + 1;

    return result;
}

int main(){
 
    int n = 5;
    double x = 3.2;
    char c = 'A';
    bool flag = false;

    // return answers
    cout<<n<<" + 1 = "<<AddOne(n)<<endl;
    cout<<x<<" + 1 = "<<AddOne(x)<<endl;
    cout<<c<<" + 1 = "<<AddOne(c)<<endl;
    cout<<flag<<" + 1 = "<<AddOne(flag)<<endl;

    return 0;
}

