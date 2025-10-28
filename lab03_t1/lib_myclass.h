#pragma once

template <class X> class MyClass{

    private:
        X value;

    public:
        MyClass(const X &value);
        void set_value(const X &value);
        const X &get_value() const;
};

#include "tpl_myclass.tpp"
