/*
========================================================
File: remove_nth_node_from_end.cpp
Concept: Linked List - Remove Nth Node From End
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Node = basic building block of Linked List
class Node{
    int data;      // stores value of node
    Node * next;   // pointer to next node

public:

    // Constructor: initialize node with value
    Node(int val){
        data = val;
        next = nullptr;
    }

    friend class LinkedList;
    friend int main();
};

class LinkedList{
    Node * head;   // pointer to first node
    Node * tail;   // pointer to last node

public:

    // Constructor: initialize empty linked list
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    /*
     * Function: push_front
     * Purpose: Insert a new node at beginning
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
     * Function: getsize
     * Purpose: Calculate size of linked list
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int getsize(){

        int sz = 0;
        Node * temp = head;

        while(temp != nullptr){
            temp = temp->next;
            sz++;
        }

        return sz;
    }

    /*
     * Function: removeNth
     * Purpose: Remove Nth node from end of linked list
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void removeNth(int n){

        int sz = getsize();

        // Case 1: Invalid value of n
        if(n <= 0 || n > sz){
            cout<<"Invalid n\n";
            return;
        }

        /*
         * Case 2: Remove first node
         *
         * Example:
         * 1 -> 2 -> 3 -> 4
         *
         * removeNth(4)
         */
        if(n == sz){

            Node * toDelete = head;

            head = head->next;

            delete toDelete;

            // If list becomes empty
            if(head == nullptr){
                tail = nullptr;
            }

            return;
        }

        Node * temp = head;

        /*
         * Move temp to node just before
         * the node to be deleted
         */
        for(int i = 1; i < sz - n; i++){
            temp = temp->next;
        }

        Node * nextnode = temp->next;

        // Connect previous node with next node
        temp->next = temp->next->next;

        /*
         * If deleted node was tail,
         * update tail pointer
         */
        if(nextnode == tail){
            tail = temp;
        }

        delete nextnode;
    }

    /*
     * Function: printList
     * Purpose: Display linked list
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

    cout<<"Linked List before deletion:\n";
    ll.printList();

    ll.removeNth(1);

    cout<<"\nLinked List after deletion:\n";
    ll.printList();

    return 0;
}
