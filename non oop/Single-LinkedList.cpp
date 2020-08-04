#include <iostream>

using namespace std;

typedef struct TElmtList *address;

typedef struct TElmtList { 
    int info; 
    address next; 
} ElmtList;

struct List { 
    address first; 
};



void CreateEmpty(List *L) { 
    (*L).first = NULL; 
}
bool IsEmpty(List L) { 
    return ((L).first == NULL); 
}

address Allocation(int x) { 
    address NewElmt; 
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
    NewElmt->info = x; 
    NewElmt->next = NULL;
    return NewElmt;
}
void Deallocation(address hapus) { 
    free(hapus); 
}
void InsertFirst(List *L, int x) { 
    address NewElmt; 
    NewElmt = Allocation(x);
    NewElmt->next = (*L).first; 
    (*L).first = NewElmt; 
}
void InsertAfter(address* PrevElement, int x){
    address NewElmt;
    NewElmt = Allocation(x);
    NewElmt->next = (*PrevElement)->next ;
    (*PrevElement)->next = NewElmt;
    
}
void InsertLast(List *L, int x){
    if(IsEmpty(*L)){
        InsertFirst(L,x);
    }else{
        address temp;
        temp = (*L).first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        InsertAfter(&temp, x);
    }
}
void DelFirst(List *L){
    address temp = (*L).first;
    (*L).first = (*L).first->next;
    temp->next = NULL;
    Deallocation(temp);

}
void DelAfter(address *PrevElmt){
    if((*PrevElmt)->next != NULL){
        address temp = (*PrevElmt)->next;
        (*PrevElmt)->next = temp->next;
        temp->info=NULL;
        Deallocation(temp);
    }
}
void DelLast(List *L){
    address temp = (*L).first;
    address last;
    while (temp->next != NULL){
        last = temp;
        temp = temp->next;
    }
    if(last == (*L).first){
        DelFirst(L);
    }else{
        DelAfter(&last);
    }

}
void printAll(List *data){
    address temp = (*data).first; 
    while (temp != NULL) { 
        cout << temp->info << endl; 
        temp = temp->next;
    }
}
int main(){
    List mahasiswa;
    
    CreateEmpty(&mahasiswa);
    InsertFirst(&mahasiswa, 10);
    InsertFirst(&mahasiswa, 20);
    InsertLast(&mahasiswa, 88);
    InsertFirst(&mahasiswa, 30);
    InsertFirst(&mahasiswa, 60);
    InsertAfter(&mahasiswa.first->next, 55);
    
    printAll(&mahasiswa);
    cout<<endl;
    DelFirst(&mahasiswa);
    DelLast(&mahasiswa);
    printAll(&mahasiswa);
    
    return 0;
}
