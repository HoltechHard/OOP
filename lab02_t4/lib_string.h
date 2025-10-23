#pragma once

class MyString{

    private:
        char *str;

    public:
        MyString();
        MyString(const char *str);
        MyString(const MyString &other);
        MyString& operator=(const MyString &other);
        ~MyString();
        char *get_string();
        int get_size();
};
