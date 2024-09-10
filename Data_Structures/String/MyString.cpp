//Implementation file for MyString Class
//This version has constructors
#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

//Default Constructor
MyString::MyString(){
    str = nullptr;
    len = 0;
}

//Parameterized Constructor
//Character array
MyString::MyString(char *ptr){
    int n = 0;
    char *temp = ptr;
    //Find length of  the char array
    while(*temp != '\0'){
        n++;
        temp++;
    }
    len = n;
    str = new char[len+1];
    for(int i = 0 ; i < (len+1) ; i++){
        str[i] = ptr[i];
    }
}

//Parameterized Constructor
//String parameter
MyString::MyString(const string &right){
    len = right.length();
    str = new char[len+1];
    for(int i = 0 ; i < (len+1) ; i++){
        str[i] = right[i];
    }
    str[len] = '\0';
}

//Copy Constructor: Uses reference object
MyString::MyString(const MyString &str_copy){
    len = 0;
    str = new char[str_copy.len + 1];
    while(len < str_copy.len){
        str[len] = str_copy.str[len];
        len++;
    }
    str[len] = '\0';
}

//Overloaded = operator
void MyString::operator = (const char *right){
    len = 0;
    while(right[len] != '\0'){
        len++;
    }
    str = new char[len+1];
    //strcpy(str,right);
    for(int i = 0 ; i < (len+1) ; i++){
        str[i] = right[i];
    }
}

//Overloaded = operator
//For string
void MyString::operator = (string &right){
    len = right.length();
    str = new char[len+1];
    //strcpy(str,right);
    for(int i = 0 ; i < (len+1) ; i++){
        str[i] = right[i];
    }
    str[len] = '\0';
}


//Const is a must here since this operator is not supposed to modify the member variable
//the const-ness of a function is part of its signature.
char MyString::operator [] (int n) const{
    return str[n];
}

//Note: You can't call a non-const method with a const object
void MyString::operator += (const MyString &r){
    int l = r.length();
    for(int i = 0 ; i < l ; i++){
        str[len+i] = r[i];
    }
    len = l+len;
    str[len] = '\0';
}

//Using friend function
//Overloaded << operator
ostream& operator << (ostream &ost,const MyString &obj){
    ost<<obj.str;
    return ost;
}

//Overloaded + operator
MyString& operator + (const MyString &left,const MyString &right){
    MyString newStr(left);
    newStr += right;
    cout<<newStr<<endl;
    return newStr;
}
