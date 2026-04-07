/*
========================================================
File: pop_front.cpp
Concept: Linked List - Deletion at Beginning
Language: C++
Author: Piyush
========================================================
*/
#include<iostream>
using namespace std;

// Node = basic building block of Linked List
class Node {
    int data;        // stores value
    Node* next;      // stores address of next node

public:
    // Constructor: initialize node with value
    Node(int val){
        data = val;
        next = nullptr; // initially no next node
    }

    // Allow List class to access private members
    friend class List;

    // Destructor: kept empty (IMPORTANT DESIGN DECISION)
    // We are NOT doing recursive deletion here
    // Reason: List class will handle deletion iteratively (safer)
    ~Node(){
        // intentionally empty
    }
};

class List{
    Node* head;   // points to first node
    Node* tail;   // points to last node

public:
    // Constructor: initialize empty list
    List(){
        head = nullptr;
        tail = nullptr;
    }

    // Destructor: deletes entire linked list (VERY IMPORTANT)
    ~List(){
        Node* temp = head;

        // Traverse entire list and delete nodes one by one
        while(temp != nullptr){
            Node* nextnode = temp->next; // save next before deleting
            delete temp;                 // delete current node
            temp = nextnode;             // move forward
        }

        // Clean final state (good practice)
        head = nullptr;
        tail = nullptr;
    }

    // Insert at beginning
 /*
     * Function: push_front
     * Purpose: Insert a new node at the beginning
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push_front(int val){
        Node* newnode = new Node(val);

        // Case 1: Empty list
        if(head == nullptr){
            head = tail = newnode; // first node becomes both head & tail
        }
        else {
            // Case 2: Non-empty list
            newnode->next = head; // new node points to old head
            head = newnode;       // update head to new node
        }
    }

    // Delete first node
    /*
     * Function: pop_front
     * Purpose: Delete the first node of the linked list
     * Time Complexity: O(1)  // direct deletion from head
     * Space Complexity: O(1)
     */
    void pop_front(){
        // Case 1: Empty list
        if(head == nullptr){
            cout << "Linked list is empty\n";
            return;
        }

        // Store current head (node to be deleted)
        Node* temp = head;

        // Move head forward
        head = head->next;

        // Break link (defensive programming)
        // Useful if destructor was recursive (prevents chain deletion)
        temp->next = nullptr;

        // Delete old head
        delete temp;

        // Case 2: List had only one node
        // Now list becomes empty → update tail also
        if(head == nullptr){
            tail = nullptr;
        }
    }

    // Print list
    /*
     * Function: print
     * Purpose: Traverse and display the linked list
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void print(){
        Node* temp = head;

        // Traverse and print each node
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {

    List ll;

    cout << "before pop front:\n";

    // Building list: 1 -> 2 -> 3
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print();

    cout << "After Pop front:\n";

    // Removing first node → 2 -> 3
    ll.pop_front();

    ll.print();

    return 0;
}
