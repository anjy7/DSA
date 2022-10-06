//n last node product

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{ 
    struct Node* new_node = new Node;
 
    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

int productOfLastN_NodesUtil(struct Node* head, int n)
{
   
    if (n <= 0)
        return 0;
 
    stack<int> st;
    int prod = 1;
 
    while (head != NULL) {
 
        st.push(head->data);
 
        head = head->next;
    }
 

    while (n--) {
        prod *= st.top();
        st.pop();
    }

    return prod;
}
 

int main()
{
    struct Node* head = NULL;
 
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 10);
 
    int n = 3;
    cout << productOfLastN_NodesUtil(head, n);
    return 0;
}