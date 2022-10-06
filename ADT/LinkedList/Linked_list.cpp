#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InstertAtHeadPosition(Node* &head,int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InstertAtTailPosition(Node* &tail,int d){
    Node *temp = new Node(d);
    tail->next = temp;
    temp->next = NULL;
}

void InsertAtPosition(Node* &head,int position,int d){
    if(position == 1){
        InstertAtHeadPosition(head,d);
        return;
    }
    Node *temp = head;
    int pos = 1;
    while(pos < position - 1){
        temp = temp->next;
        pos++;
    }

    Node *insert = new Node(d);

    insert->next = temp->next;
    temp->next = insert;


}

void display(Node* &head){
    Node* temp = head;

    while (temp != NULL )
    {
        cout << temp -> data << " ";
        temp = temp->next;
    }
 
}

int main(){
    Node *node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    InstertAtHeadPosition(head,9);
    InstertAtTailPosition(tail,11);
    display(head);
    return 0;
}