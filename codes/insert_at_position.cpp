/*
========================================================
File: insert_at_position.cpp
Concept: Linked List - Insert at Position
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Node = basic building block of Linked List
class Node {
    int data;      // stores value of node
    Node * next;   // pointer to next node

public:
    // Constructor: initialize node with value
    Node (int val) {
        data = val;
        next = nullptr;   // initially points to nothing
    }

    // Allow List class to access private members
    friend class List;
};

class List {
    Node * head;   // pointer to first node
    Node * tail;   // pointer to last node

public:

    // Constructor: initialize empty linked list
    List() {
        head = nullptr;
        tail = nullptr;
    }

    /*
     * Function: push_back
     * Purpose: Insert a new node at the end of the linked list
     * Time Complexity: O(1)  // direct insertion using tail
     * Space Complexity: O(1)
     */
    void push_back(int val) {
        Node * newnode = new Node(val);

        // Case 1: Empty list
        if(head == nullptr){
            head = tail = newnode;
        } 
        else {
            // Case 2: List already has elements
            tail->next = newnode;  // connect last node to new node
            tail = newnode;        // update tail
        }
    }

    /*
     * Function: push_front
     * Purpose: Insert a new node at the beginning of the linked list
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push_front(int val){
        Node * newnode = new Node(val);

        // Edge Case: Empty list
        if (head == nullptr) {
            head = tail = newnode;
        } 
        else {
            // Connect new node before current head
            newnode->next = head;
            head = newnode;
        }
    }

    /*
     * Function: insert
     * Purpose: Insert a new node at a given position
     * Positioning: 0-based index
     * Time Complexity: O(n)  // traversal required
     * Space Complexity: O(1)
     */
    void insert(int val, int pos) {

        // Case 0: Invalid negative position
        if(pos < 0){
            cout << "Invalid Position\n";
            return;
        }

        // Case 1: Insert at beginning
        // Reuse push_front() to avoid code duplication
        if(pos == 0){
            push_front(val);
            return;
        }

        Node * temp = head;

        // Move temp to the node just before desired position
        // Example:
        // List: 1 -> 2 -> 3
        // insert(99,2) → temp should stop at node with value 2
        for(int i = 0; i < pos - 1; i++){
            if(temp == nullptr) {
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }

        // Extra safety check (defensive programming)
        if(temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }

        Node * newnode = new Node(val);

        // IMPORTANT ORDER:
        // Step 1: Connect new node to next node
        newnode->next = temp->next;

        // Step 2: Connect previous node to new node
        // If reversed, remaining list can be lost
        temp->next = newnode;

        // If inserted at end, update tail
        if(newnode->next == nullptr){
            tail = newnode;
        }
    }

    /*
     * Function: print
     * Purpose: Traverse and display the linked list
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void print (){
        Node * temp = head;

        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){
    List ll;
    
    cout << "Linked list before insertion:\n";
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    ll.print();

    cout << "After inserting 0 at position 0:\n";
    ll.insert(0, 0); 
    ll.print();

    return 0;
}
