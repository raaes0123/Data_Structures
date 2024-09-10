#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string>
using namespace std;

class MyString{
    private:
        char *str;
        int len;
    public:
        //Default Constructor
        MyString ();
        //Parameterized Constructor Declaration
        MyString(char *);
        MyString(const string &);
        //Copy Constructor
        MyString(const MyString &);     //Remember a pass by ref is needed here
        //Overloaded = Operator
        void operator = (const char *right);
        //Overloaded = Operator for String
        void operator = (string &);
        //Overloaded [] Operator
        char operator [] (int n) const;
        //Overloaded += Operator
        void operator += (const MyString &);
        //Destructor
        ~MyString(){
            delete [] str;
        }
        //Accessor
        int length() const {
            return len;
        }
        //Friend function
        //If you are overloading << operator as a member function,
        //the first parameter is implicitly the calling object.
        //You should either overload it as friend function or as a free function. 
        //Overloaded << operator
        friend ostream& operator << (ostream &,const MyString &);
        friend MyString& operator + (const MyString &,const MyString &);
};
#endif