#include<iostream>
#include "BinaryTree.h"
using namespace std;

//****Private Funtions******//
//Insertion by recursion
//Note The nodePtr and newNode parameter is not simply a pointer to a TreeNode structure, but a reference
//to a pointer to a TreeNode structure. This means that any action performed on nodePtr
//is actually performed on the argument that was passed into nodePtr
void BinaryTree::insert(TreeNode *&nodePtr,TreeNode *&newNode){
    //if the tree is empty
    if(nodePtr == nullptr){
        nodePtr = newNode;
        cout<<"Node inserted: "<<nodePtr->value<<endl;
    }
    else if(newNode->value < nodePtr->value)
        insert(nodePtr->left,newNode);
    else
        insert(nodePtr->right,newNode);
}

void BinaryTree::makeDeletion(TreeNode *&nodePtr){
    //Delete the node corresponding to 'num'
    //Also make sure the node's children node are properly placed
    //There is no problem if a node is a leaf node
    //If the node has a single child node, the child node takes it's place after it is deleted
    //If the node has left and right nodes then the right node takes the place and left node
    //is accomodated as its child
    TreeNode *tempNode = nullptr;
    cout<<"Node "<<nodePtr->value<<endl;
    if(nodePtr == nullptr)
        cout<<"Cannot delete empty node.\n";
    else if(nodePtr->left == nullptr && nodePtr->right == nullptr){
        tempNode = nodePtr;
        cout<<"Code reached here"<<endl;
        cout<<"Deleting"<<nodePtr->value<<endl;
        delete tempNode;
        nodePtr = nullptr;
    }
    else if(nodePtr->left == nullptr && nodePtr->right != nullptr){
        tempNode = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNode;
    }
    else if(nodePtr->left != nullptr && nodePtr->right == nullptr){
        tempNode = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNode;
    }
    else{
        //If the node has left and right nodes then the right node takes the place and left node
        tempNode = nodePtr;
        nodePtr = nodePtr->right;
        //Go to the left most leaf node
        while(nodePtr->left)
            nodePtr = nodePtr->left;
        //Attach the left pointer of the deleted node ie tempNode->left node here
        nodePtr->left = tempNode->left;
        delete tempNode;

    }
}

void BinaryTree::deleteNode(int num, TreeNode *&nodePtr){
    if(num < nodePtr->value)
        deleteNode(num,nodePtr->left);
    else if(num > nodePtr->value)
        deleteNode(num,nodePtr->right);
    else
    {
        cout<<"Make deletion called for "<<nodePtr->value;
        cout<<"Condition satisfied for "<<nodePtr->value<<"equal to "<<num<<endl;
        makeDeletion(nodePtr);
    }
}
void BinaryTree::destroySubTree(TreeNode* nodePtr){
    //Assuming the node is present in the tree
    //Use recursion
    if(nodePtr){
        if(nodePtr->left){
            destroySubTree(nodePtr->left);
        }
        if(nodePtr->right){
            destroySubTree(nodePtr->right);
        }
        delete nodePtr;
    }
}

void BinaryTree::destroy(int num,TreeNode* nodePtr){
    if(num == nodePtr->value){
        destroySubTree(nodePtr);
    }
    else{
        if(nodePtr->left)
            destroy(num,nodePtr->left);
        if(nodePtr->right)
            destroy(num,nodePtr->right);
    }
}


void BinaryTree::displayPreOrder(TreeNode *nodePtr) const{
    if(nodePtr != nullptr){
        cout<<nodePtr->value<<endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BinaryTree::displayInOrder(TreeNode *nodePtr) const{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout<<nodePtr->value<<endl;
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::displayPostOrder(TreeNode *nodePtr) const{
    if(nodePtr != nullptr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout<<nodePtr->value<<endl;
    }
}

//*******Public Functions*********//

void BinaryTree::insertNode(int num){
    TreeNode *newNode = nullptr;
    newNode = new TreeNode();
    newNode->value = num;
    newNode->left = nullptr;
    newNode->right = nullptr;
    insert(root,newNode);
}

bool BinaryTree::searchNode(int num){
    TreeNode *nodePtr = root;
    while(nodePtr){
        if(nodePtr->value == num){
            return true;
        }
        else if(num < nodePtr->value){
            nodePtr = nodePtr->left;
        }
        else{
            nodePtr = nodePtr->right;
        }
    }
    return false;
}
