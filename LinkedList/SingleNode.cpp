#include <cstdlib>
#include <iostream>

#include "SingleNode.h"

using namespace std;

SingleNodeList::SingleNodeList(){
    head = NULL;
    curr = NULL;
    temp = NULL;
} //ITS CONSTRUCTOR THAT SET ALL VARIABLE TO NULL

void SingleNodeList::addNode(int Newdata){
    nodeptr newNode = new node; // creating new node at heap memory
    
    newNode->NEXT = NULL; //set NEXT newNode element to NULL

    newNode->data = Newdata; //Inserting newDATA to newData

    if(head != NULL){
        curr =  head;

        while (curr->NEXT != NULL){
            curr = curr->NEXT;
        }//go to the last node with
        
        curr->NEXT = newNode; //assign newNode address to NEXT element on the last node
    }else{
        head = newNode;
    }
}


void SingleNodeList::DeleteNode(int delData){
    nodeptr delNode = NULL;
    
    temp = head;
    curr = head;

    while( curr != NULL && curr->data != delData){
        temp = curr;
        curr = curr->NEXT;
    }

    if(curr == NULL){
        cout << delData <<" DO NOT EXIST IN THE LIST\n";
        delete delNode;
    }
    else{
        delNode = curr;
        curr = curr->NEXT;
        temp->NEXT = curr;
        if(delNode == head){
            head = head->NEXT;
            temp = NULL;
        }
        delete delNode;
        cout << delData <<" HAS BEEN DELETED\n";
    }
}


void SingleNodeList::PrintList(){
    curr = head;

    while (curr != NULL){
        cout << curr->data << endl;
        curr = curr->NEXT;
    }
}