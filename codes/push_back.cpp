/*
========================================================
File: push_back.cpp
Concept: Linked List - Insertion at End
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Node class represents a single element of the Linked List
class Node {
    int data;        // stores the value of the node
    Node * next;     // pointer to the next node

public:
   
    // Constructor to initialize node with given value
    Node (int val) {
        data = val;
        next = nullptr;   // initially points to nothing
    }

    // Allow LinkedList class to access private members
    friend class LinkedList;
};


// LinkedList class to manage operations on the list
class LinkedList {
    Node* head;   // pointer to first node
    Node* tail;   // pointer to last node

public:

    // Constructor initializes an empty list
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /*
     * Function: push_back
     * Purpose: Insert a new node at the end of the list
     * Time Complexity: O(1)  // direct access using tail, no traversal required
     * Space Complexity: O(1)
     */
    void push_back(int val) {
        Node * newNode = new Node(val);   // create new node dynamically

        // Edge Case:
        // If list is empty, both head and tail point to new node
        if(head == nullptr) {
            head = tail = newNode;
        } 
        else {
            // Case: List already has elements
            tail->next = newNode;   // current tail points to new node
            tail = newNode;         // update tail to new node
        }
    }

    /*
     * Function: print
     * Purpose: Traverse and display the linked list
     * Time Complexity: O(n)  // traverse entire list
     * Space Complexity: O(1)
     */
    void print() {
        Node * temp = head;   // start traversal from head

        while(temp != nullptr) {
            cout << temp->data << " ->";
            temp = temp->next;   // move to next node
        }

        cout << "NULL" << endl;
    }
};


int main() {
    LinkedList ll;

    // Insert elements at end
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    // Expected Output: 1 -> 2 -> 3 -> NULL
    ll.print();

    return 0;
}
