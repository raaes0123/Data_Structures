#include<iostream>
#include "IntStack.h"

using namespace std;

int main(){
    IntStack st;
    st.push(1);
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.push(2);
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.push(3);
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.push(4);
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    st.pop();
    cout<<"Stack size: "<<st.size()<<" Top: "<<st.top()<<endl;
    return 0;
}