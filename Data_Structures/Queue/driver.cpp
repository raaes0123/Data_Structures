#include<iostream>
#include "Queue.h"
using namespace std;

int main(){
    IntQueue Q;
    if(Q.isEmpty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;
    cout<<"Pushing 1 to queue"<<endl;
    Q.push_back(1);
    cout<<"Pushing 2 to queue"<<endl;
    Q.push_back(2);
    cout<<"Pushing 3 to queue"<<endl;
    Q.push_back(3);
    cout<<"Queue size: "<<Q.size()<<endl;
    cout<<"Popping from queue"<<endl;
    cout<<Q.pop_front()<<endl;
    cout<<"Popping from queue"<<endl;
    cout<<Q.pop_front()<<endl;
    cout<<"Popping from queue"<<endl;
    cout<<Q.pop_front()<<endl;
    cout<<"Popping from queue"<<endl;
    cout<<Q.pop_front()<<endl;
    return 0;
}