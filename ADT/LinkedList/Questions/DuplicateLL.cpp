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

Node* removeDuplicateSorted(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node *curr = head;

    while (curr != NULL)
    {
        if(curr->next != NULL && curr->data == curr->next->data){
            Node* next2next = curr->next->next;
            Node* node2delete = curr->next;
            delete(node2delete);
            curr->next = next2next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
    
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

   
    return 0;
}