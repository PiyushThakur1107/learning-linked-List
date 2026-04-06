
/*
========================================================
File: push_front.cpp
Concept: Linked List - Insertion at Beginning
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Node class represents a single element of the Linked List
class Node {
    int data;      // stores the value of the node
    Node * next;   // pointer to the next node

public:
    
    // Constructor to initialize node with given value
    Node(int val) {
        data = val;
        next = nullptr;   // initially, node does not point to anything
    }

    // Allow Linkedlist class to access private members (data, next)
    friend class Linkedlist;
};


// Linkedlist class to manage operations on the list
class Linkedlist {
   Node * head;   // pointer to first node
   Node * tail;   // pointer to last node

public:

   // Constructor initializes an empty list
   Linkedlist() {
       head = nullptr;
       tail = nullptr;
   }

   /*
    * Function: pushfront
    * Purpose: Insert a new node at the beginning of the list
    * Time Complexity: O(1)
    * Space Complexity: O(1)
    */
   void push_front(int val){
     Node * newnode = new Node(val);   // create new node dynamically

       // Edge Case:
// If the list is empty, both head and tail must point to the new node
     if (head == NULL) {
        head = tail = newnode;   
     } 
     else {
        // Case 2: List already has elements
        newnode->next = head;   // new node points to current head
        head = newnode;         // update head to new node
     }
   }

   /*
    * Function: print
    * Purpose: Traverse and display the linked list
    * Time Complexity: O(n)
    * Space Complexity: O(1)
    */
   void print() {
    Node * temp = head;   // start traversal from head

    // Traverse until end (NULL)
    while(temp != NULL){
        cout << temp->data << " ->";
        temp = temp->next;   // move to next node
    }

    cout << "NULL" << endl;   // indicates end of list
   }
};


int main() {
    Linkedlist ll;   // create linked list object

    // Insert elements at front
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // Expected Output: 1 -> 2 -> 3 -> NULL
    ll.print();

    return 0;
}
