#ifndef SINGLENODE
#define SINGLENODE

#include <iostream>

class SingleNodeList{
    private:

        struct node{
            int data;
            
            node* NEXT;
        };
        
        typedef node* nodeptr;
    
        nodeptr head;
        nodeptr curr;
        nodeptr temp;
    public:
        //list of function that could manipulate data;

        SingleNodeList();//its constructor
        void addNode(int data);
        void DeleteNode(int data);
        void PrintList();
};

#endif