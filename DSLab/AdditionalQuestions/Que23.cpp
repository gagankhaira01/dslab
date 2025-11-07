#include<iostream>
using namespace std; 

// Node of a doubly linked list
class Node
{
    public:
    int data;
    // Pointer to next node in DLL
    Node *next;
      
      // Pointer to previous node in DLL
    Node *prev;

    Node():prev(NULL),next(NULL){}
    Node(int data):data(data),prev(NULL),next(NULL){}

};
class doublell
{
    public:
    Node *head;
    // Function to append node in the DLL
    void appendNode(Node *n)
    {
        Node *temp=head;
        if(temp==NULL)
        {
            head=n;
            
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
        }
    }
      // Function to print the DLL
    void print()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
      // Function to print reverse of the DLL
    void printReverse()
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ->";
            temp=temp->prev;
        }
        cout<<endl;
    }
    // Function to correct the random pointer
    void correctPointer()
    {
        if(!head)
        {
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->prev!=temp)
            {
                temp->next->prev=temp;
            }
            temp=temp->next;
        }
    }
};

// Driver Code
int main() 
{ 
  
    // Creating a DLL 
    doublell ll;
    ll.head = new Node(1); 
    ll.head->next = new Node(2); 
    ll.head->next->prev = ll.head; 
    ll.head->next->next = new Node(3); 
    ll.head->next->next->prev =ll.head; 
    ll.head->next->next->next = new Node(4); 
    ll.head->next->next->next->prev = ll.head->next->next; 
  
    cout << "\nIncorrect Linked List: "; 
    ll.print(); 
    ll.printReverse();
  
    ll.correctPointer(); 
  
    cout << "\nCorrected Linked List: "; 
    ll.print(); 
    ll.printReverse();

  
    return 0; 
}