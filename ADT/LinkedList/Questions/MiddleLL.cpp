#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty !!" << endl;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}

void Insert_At_Tail(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return;
}

void findMiddle(Node *head) {
   
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        temp=temp->next;
        count++;
    }
    Node *temp2 = head;
    int target = count/2;
    int i = 0;
    while(i < target){
        temp2 = temp2->next;
        i++;
    }
    cout<<"middle: "<<temp2->data<<endl;
}

void findMiddleOptimised(Node *head) {
   
    // Node *first = head->next;
    // Node *second = head;
    // while(first != NULL){
    //     first = first->next;
    //     if(first != NULL){
    //         first = first->next;
    //     }
    //     second = second->next;
    // }
    
    Node *first = head;
    Node *second = head; 
    while(first != NULL && first->next != NULL){
        first = first->next->next;
        second = second->next;
    }
    
    cout<<"optimised middle: "<<second->data<<endl;
}


int main()
{
    Node *head = NULL;
    int n, data;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data: ";
        cin >> data;
        Insert_At_Tail(head, data);
    }
    cout << "Linked List: ";
    print(head);

    findMiddle(head);
    findMiddleOptimised(head);

    return 0;
}