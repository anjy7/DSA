// C++ Code in Odd -> Even Index Position
#include<bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

// A utility function to create a new node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void swap(int n1, int n2,Node *head){  
    struct Node *prevNode1 = NULL, *prevNode2 = NULL, *node1 = head, *node2 = head, *temp = NULL;  
      
    //Checks if list is empty  
    if(head == NULL) {  
        return;  
    }  
          
    //If n1 and n2 are equal, then list will remain the same  
    if(n1 == n2)  
        return;  
      
    //Search for node1  
    while(node1 != NULL && node1->data != n1){  
        prevNode1 = node1;  
        node1 = node1->next;  
    }  
      
    //Search for node2  
    while(node2 != NULL && node2->data != n2){  
        prevNode2 = node2;  
        node2 = node2->next;  
    }  
      
    if(node1 != NULL && node2 != NULL) {  
          
        //If previous node to node1 is not null then, it will point to node2  
        if(prevNode1 != NULL)  
            prevNode1->next = node2;          
        else  
            head  = node2;  
          
        //If previous node to node2 is not null then, it will point to node1  
        if(prevNode2 != NULL)  
            prevNode2->next = node1;  
        else  
            head  = node1;  
          
        //Swaps the next nodes of node1 and node2  
        temp = node1->next;   
        node1->next = node2->next;   
        node2->next = temp;       
    }      
    else{  
        printf("Swapping is not possible\n");  
    }  
}  


void rearrangeEvenOdd(Node *head)
{

if(head==NULL || head->next == NULL){
	// 0 or 1 node
	return;
}
Node* temp = head;


int i = 1;
while(temp != NULL){

     swap(i,i+1,head);

	
	temp = temp->next;
	
	i++;
}

}

void printlist(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

// Driver code
int main(void)
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);

	cout << "Given Linked List\n";
	printlist(head);

	rearrangeEvenOdd(head);

	cout << "\nModified Linked List\n";
	printlist(head);

	return 0;
}
