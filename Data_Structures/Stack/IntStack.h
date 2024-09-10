//Specification file for IntStack Class implemented as linked list
#ifndef INTSTACK_H
#define INTSTACK_H

class StackNode{
    public:
        StackNode *next;
        int val;
        StackNode(){
            next = nullptr;
        }
};
class IntStack{
    private:
        StackNode *stack_top;    //Pointer to the stack array
        int stack_size;
    public:
        IntStack(){
            stack_top = nullptr;
            stack_size = 0;
        }
        void push(int);
        void pop();
        int top();
        bool isEmpty();
        int size();
};

#endif