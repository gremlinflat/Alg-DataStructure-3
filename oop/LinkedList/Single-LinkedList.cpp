#include <iostream>
#include "SingleNode.h"
#include "SingleNode.cpp"
using namespace std;

int main(){
    SingleNodeList newlist;
    newlist.addNode(6);
    newlist.addNode(7);
    newlist.addNode(4);
    newlist.addNode(2);
    newlist.addNode(1);
    newlist.PrintList();
    cout<<endl;
    newlist.DeleteNode(6);
    newlist.PrintList();
    
    return 0;
}
