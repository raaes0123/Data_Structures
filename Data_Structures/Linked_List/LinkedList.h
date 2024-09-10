//A class template for holding a linked list
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

//ListNode Class
class ListNode{
    public:
        int val;            //Node value
        ListNode* next;   //Pointer to next node
        //Constructor
        ListNode(){
            next = nullptr;
        }
        ListNode(int value): val(value), next(nullptr) {}
};

//Linked List Class
class LinkedList{
    private:
        ListNode *head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void appendNode(int);
        void displayList();
        void deleteNode(int);
        //~LinkedList();

};

void LinkedList::appendNode(int val){
    //Create a new node with give value
    ListNode *node = new ListNode(val);
    ListNode *temp_head;
    //If the head points to null this is the first node and make the head point to this node
    if(!head){
        head = node;
    }
    else{
        temp_head = head;
        //Go through the list till you reach the node that points to null
        while(temp_head->next){
            temp_head = temp_head->next;
        }
        //Insert new node as the last node
        temp_head->next = node;
    }
}

void LinkedList::displayList(){
    ListNode *temp_head;
    temp_head = head;
    //Go through the list till you reach the tail(nullptr) and print out the value
    while(temp_head){
        cout<<temp_head->val<<" -> ";
        temp_head = temp_head->next;
    }
    cout<<"Null"<<endl;
}

void LinkedList::deleteNode(int num){
    //Temporary head pointer
    ListNode *temp_head;
    temp_head = head;
    //If list has no node
    if(!head){
        cout<<"Empty List";
        return;
    }
    //If the head is the node to be deleted
    if(temp_head->val == num){
        head = head->next;
        delete temp_head;
        return;
    }
    //Traverse through the list till you reach the node that points to null or find the value num
    while(temp_head->next){
        ListNode *nextNode;
        nextNode = temp_head->next;
        if(nextNode->val == num){
            temp_head->next = nextNode->next;
            //Delete that node
            delete nextNode;
            return;
        }
        else{
            temp_head = temp_head->next;
        }
    }
}
#endif
