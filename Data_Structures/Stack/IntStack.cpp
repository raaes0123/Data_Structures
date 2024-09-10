#include<iostream>
#include "IntStack.h"

using namespace std;

//************************************************* 
// Member function push pushes the argument onto * 
// the stack. * 
//************************************************* 
void IntStack::push(int num){
    //Create a new node
    StackNode *newNode;
    newNode = new StackNode;
    newNode->val = num;
    if(stack_size == 0){
        stack_top = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode->next = stack_top;
        stack_top = newNode;
    }
    stack_size++;
}

//************************************************* 
// Member function pop pops the element from the * 
// stack. * 
//************************************************* 
void IntStack::pop(){
    //Prevent pop if empty
    if(!isEmpty()){
        cout<<"Popping"<<endl;
        StackNode *tempNode = nullptr;
        tempNode = stack_top->next;
        delete stack_top;               //De-allocate memory
        stack_top = tempNode; 
        stack_size--;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}
//************************************************* 
// Member function top returns the top of the 
// stack.
//************************************************* 
int IntStack::top(){
    if(stack_size>0)
        return stack_top->val;
    else
        return -1;
}

//************************************************* 
// Member function isEmpty returns true if empty * 
//************************************************* 
bool IntStack::isEmpty(){
    return stack_size == 0;
}
//************************************************* 
// Member function size returns the size of the
// stack
//************************************************* 
int IntStack::size(){
    return stack_size;
}