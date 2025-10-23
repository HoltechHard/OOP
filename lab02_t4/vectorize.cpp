#include <iostream>
#include "lib_vector.h"

using namespace std;

Vector::Vector(){
    this->x = this->y = 0;
}

Vector::Vector(double x, double y){
    this->x = x;
    this->y = y;
}

Vector &Vector::operator=(const Vector &v){
    if(this == &v)
        return *this;
    
    this->x = v.x;
    this->y = v.y;

    return *this;
}

void Vector::print(){
    cout<<"\n Vector: x = "<<this->x<<" , "<<"y = "<<this->y<<endl;
}
