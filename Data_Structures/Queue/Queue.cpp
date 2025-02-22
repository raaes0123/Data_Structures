#include <iostream>
#include "Queue.h"

IntQueue::IntQueue(){
    q = new int;
    index = 0;
    size_alloted = 1;
}

bool IntQueue::isEmpty(){
    return index == 0;
}

int IntQueue::size(){
    return index;
}

void IntQueue::push_back(int n){
    int size = index;
    // First check if the alloted size is filled up
    if(size == size_alloted){
        // Double the size
        // Store the current in a temp variable
        int *temp = new int[size];
        memcpy(temp,q,size*sizeof(int));
        // Delete previous allocation
        delete [] q;
        // Fresh allocation with double the size
        q = new int[2*size];
        memcpy(q,temp,size*sizeof(int));
        // Delete temp allocation
        delete [] temp;
        size_alloted *= 2;
    }
    q[index++] = n;
}

int IntQueue::pop_front(){
    // Make sure the queue is not empty
    if(isEmpty()){
        std::cerr << "The queue is empty\n";
        return -1;
    }
    // Get the first item from array
    int return_val = q[0];
    // Handle the case when size = 1 (Just decrement by 1)
    if(index == 1){
        index--;
        return return_val;
    }
    // Move the items from the queue except the first to the front of the queue
    memmove(q,q+1,(index-1)*sizeof(int));
    index--;
    return return_val;
}