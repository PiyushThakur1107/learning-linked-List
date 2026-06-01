/*
========================================================
File: remove_cycle.cpp
Concept: Linked List - Detect and Remove Cycle
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Node = basic building block of Linked List
class Node{
    int data;      // stores value
    Node * next;   // points to next node

public:

    // Constructor: initialize node
    Node(int val){
        data = val;
        next = nullptr;
    }

    friend class LinkedList;
    friend int main();
};

class LinkedList{
    Node * head;   // first node
    Node * tail;   // last node

public:

    // Constructor: initialize empty linked list
    LinkedList(){
        head = nullptr;
        tail = nullptr;
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
            head = newnode;
        }
    }

    /*
     * Function: isCycle
     * Purpose: Check whether cycle exists or not
     * Algorithm: Floyd's Cycle Detection Algorithm
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    bool isCycle(Node * head){

        Node * slow = head;
        Node * fast = head;

        while(fast != nullptr && fast->next != nullptr){

            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            // If both pointers meet, cycle exists
            if(slow == fast){
                cout<<"Cycle Detected\n";
                return true;
            }
        }

        cout<<"Cycle Not Detected\n";
        return false;
    }

    /*
     * Function: removeCycle
     * Purpose: Detect and remove cycle
     * Algorithm: Floyd's Cycle Detection + Cycle Removal
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void removeCycle(Node * head){

        Node * slow = head;
        Node * fast = head;

        bool isCycle = false;

        // Step 1: Detect Cycle
        while(fast != nullptr && fast->next != nullptr){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                cout<<"Cycle Detected\n";
                isCycle = true;
                break;
            }
        }

        // Case 1: No cycle present
        if(!isCycle){
            cout<<"Cycle Not Detected\n";
            return;
        }

        // Step 2: Move slow back to head
        slow = head;

        /*
         * Special Case:
         * Cycle starts from head
         *
         * Example:
         * 1 -> 2 -> 3 -> 4
         * ^              |
         * |______________|
         */
        if(slow == fast){

            // Move fast to last node of cycle
            while(fast->next != slow){
                fast = fast->next;
            }

            // Remove cycle
            fast->next = nullptr;
        }

        /*
         * General Case:
         * Cycle starts somewhere in middle
         *
         * Example:
         * 1 -> 2 -> 3 -> 4 -> 5
         *           ^         |
         *           |_________|
         */
        else{

            Node * prev = fast;

            while(slow != fast){

                slow = slow->next;

                prev = fast;
                fast = fast->next;
            }

            // prev points to node just before cycle start
            prev->next = nullptr;
        }

        cout<<"Cycle Removed Successfully\n";
    }

    /*
     * Function: printList
     * Purpose: Display Linked List
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void printList(){

        Node * temp = head;

        while(temp != nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

    friend int main();
};

int main(){

    LinkedList ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // Creating Cycle
    // 1 -> 2 -> 3 -> 4
    // ^              |
    // |______________|

    ll.tail->next = ll.head;

    ll.removeCycle(ll.head);

    cout<<"Linked List after removing cycle:\n";
    ll.printList();

    return 0;
}
