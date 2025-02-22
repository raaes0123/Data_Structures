// A class for holding a queue data structure

//#pragma once
#ifndef QUEUE_H
#define QUEUE_H
class IntQueue{
    private:
        int *q;
        int index;
        int size_alloted;
    public:
        IntQueue();
        bool isEmpty();
        int size();
        void push_back(int n);
        int pop_front();
};
#endif