#include<iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    cout<<"Hello"<<endl;
    cout<<"World"<<endl;
    BinaryTree tree;
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);
    cout<<"In Order"<<endl;
    tree.displayInOrder();
    tree.deleteSubTree(8);
    cout<<"InOrder after deletion"<<endl;
    tree.displayInOrder();
    return 0;
}