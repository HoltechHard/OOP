#ifndef LIB_MYCLASS_TPP
#define LIB_MYCLASS_TPP

template <class X>
MyClass<X>::MyClass(const X &value){
    this->value = value;
}

template <class X>
void MyClass<X>::set_value(const X &value){
    this->value = value;
}

template <class X>
const X &MyClass<X>::get_value() const{
    return this->value;
}

#endif //LIB_MYCLASS_TPP
