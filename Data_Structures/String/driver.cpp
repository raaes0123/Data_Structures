#include<iostream>
#include "MyString.h"
using namespace std;

int main(){
    MyString str3;
    MyString str1 = (char*)"Hello!!!";              //Overload =
    MyString str2 = str1;           //Copy Constructor
    str1 = "World!!!";
    str3 = str1;                    //Copy Assignment
    cout<<"String length: "<<str2.length()<<endl;
    cout<<"String: "<<str2<<endl;
    cout<<"String length: "<<str3.length()<<endl;
    cout<<"String: "<<str3<<endl;
    MyString str = "Hello World!!!";      //Parameterized constructor
    cout<<"String length: "<<str.length()<<endl;
    cout<<"String: "<<str<<endl;
    cout<<"Char at position 6 is "<<str[6]<<endl;
    MyString str4,str5,str6;
    str4 = "Good ";
    str5 = "news!";
    str4 += str5;
    cout<<str4<<endl;
    cout<<"New Length: "<<str4.length()<<endl;
    str6 = str4 + str5;
    cout<<str6<<endl;
    return 0;
}