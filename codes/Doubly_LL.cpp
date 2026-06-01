/*
========================================================
File: doubly_linked_list.cpp
Concept: Doubly Linked List - Insertion and Deletion
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Node = basic building block of Doubly Linked List
class Node{
    int data;      // stores value
    Node * next;   // points to next node
    Node * prev;   // points to previous node

public:

    // Constructor: initialize node
    Node(int val){
        data = val;
        next = prev = nullptr;
    }

    friend class DoublyLL;
    friend int main();
};

class DoublyLL{

    Node * head;   // pointer to first node
    Node * tail;   // pointer to last node

public:

    // Constructor: initialize empty linked list
    DoublyLL(){
        head = tail = nullptr;
    }

    /*
     * Function: push_front
     * Purpose: Insert node at beginning
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push_front(int val){

        Node * newnode = new Node(val);

        // Case 1: Empty Linked List
        if(head == nullptr){
            head = tail = newnode;
        }

        // Case 2: Linked List already contains nodes
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    /*
     * Function: push_back
     * Purpose: Insert node at end
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push_back(int val){

        Node * newnode = new Node(val);

        // Case 1: Empty Linked List
        if(head == nullptr){
            head = tail = newnode;
        }

        // Case 2: Linked List already contains nodes
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    /*
     * Function: pop_front
     * Purpose: Delete first node
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void pop_front(){

        // Case 1: Empty Linked List
        if(head == nullptr){
            cout<<"Linked List Empty\n";
            return;
        }

        // Case 2: Single Node Linked List
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }

        Node * toDelete = head;

        head = head->next;

        head->prev = nullptr;

        toDelete->next = nullptr;

        delete toDelete;
    }

    /*
     * Function: pop_back
     * Purpose: Delete last node
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void pop_back(){

        // Case 1: Empty Linked List
        if(head == nullptr){
            cout<<"Linked List Empty\n";
            return;
        }

        // Case 2: Single Node Linked List
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }

        Node * toDelete = tail;

        tail = tail->prev;

        tail->next = nullptr;

        delete toDelete;
    }

    /*
     * Function: printList
     * Purpose: Display Doubly Linked List
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void printList(){

        Node * temp = head;

        while(temp != nullptr){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

    friend int main();
};

int main(){

    DoublyLL ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(4);
    ll.push_back(5);

    cout<<"Head: "<<ll.head->data<<"\n";
    cout<<"Tail: "<<ll.tail->data<<"\n";

    cout<<"\nDoubly Linked List:\n";
    ll.printList();

    ll.pop_front();
    ll.pop_back();

    cout<<"\nAfter Deletion:\n";

    cout<<"Head: "<<ll.head->data<<"\n";
    cout<<"Tail: "<<ll.tail->data<<"\n";

    ll.printList();

    return 0;
}
