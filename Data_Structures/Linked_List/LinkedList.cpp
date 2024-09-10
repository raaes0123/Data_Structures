#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList ll;
    ll.appendNode(1);
    ll.appendNode(2);
    ll.appendNode(3);
    ll.appendNode(4);
    ll.displayList();
    ll.deleteNode(1);
    ll.displayList();
    return 0;
}