#include <iostream>
#include <cstring>
#include "lib_string.h"

using namespace std;

MyString::MyString(){
    this->str = nullptr;
}

MyString::MyString(const char *str){
    if(str){
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }else{
        this->str = nullptr;
    }    
}

MyString::MyString(const MyString &other){
    if (other.str) {
        this->str = new char[strlen(other.str) + 1];
        strcpy(this->str, other.str);
    } else {
        this->str = nullptr;
    }
}

MyString& MyString::operator=(const MyString& other) {
    if (this == &other) 
        return *this;

    delete[] str;
    this->str = nullptr;

    if (other.str) {
        this->str = new char[strlen(other.str) + 1];
        strcpy(this->str, other.str);
    }

    return *this;
}

MyString::~MyString(){
    delete[] this->str;
}

char *MyString::get_string(){
    return this->str;
}

int MyString::get_size(){
    return strlen(this->str) + 1;
}
