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

void reverseLinkedList(Node *&head) 
{

        Node *prev = NULL;
        Node *curr = head;
        Node *frwd = NULL;
        
        while(curr != NULL){
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        head = prev;
    
}


 
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

    reverseLinkedList(head);
    cout << "Reversed Linked List 2: ";
    print(head);

    return 0;
}