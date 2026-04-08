/*
========================================================
File: pop_back.cpp
Concept: Linked List - Deletion at End
Language: C++
Author: Piyush
========================================================
*/
#include<iostream>
using namespace std;

class Node {
    int data;
    Node * next;
    public:
     Node(int val){
        data = val;
        next = nullptr;
     }
     friend class List;


     ~Node(){

     }
};

class List{
    Node * head;
    Node * tail;
    public:
    List(){
        head = nullptr;
        tail = nullptr;
    }



   ~ List(){
    Node * temp = head;
    while(temp != nullptr){
        Node * nextnode = temp->next;
        delete temp;
        temp=nextnode;
    }
    head = nullptr;
    tail = nullptr;
    }
      
/*
     * Function: push_front
     * Purpose: Insert a new node at the beginning
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push_front(int val){
        Node * newnode = new Node(val);
       if(head == nullptr){
         head = tail = newnode;
       } else {
         newnode->next=head;
         head=newnode;
       }
    }

/*
 * Function: pop_back
 * Purpose: Delete the last node of the linked list
 * Time Complexity: O(n)  // traversal is needed to reach second last node
 * Space Complexity: O(1)
 */
    void pop_back() { 

        // Case 1: Empty list → nothing to delete
        if(head == nullptr) {
            cout<<"empty linked list\n";
            return;
        }
    
        // Case 2: Only one node present
        // head and tail both point to same node
        if(head == tail){
            delete head;           // delete the only node
            head = tail = nullptr;    // list becomes empty
            return;
        }
    
        // Case 3: More than one node
        // Goal: reach the node just BEFORE tail (second last node)
        Node * temp = head;
    
        // Move temp until it reaches second last node
        // i.e., stop when temp->next->next == nullptr
        // Example: 1->2->3->4
        // temp should stop at 3 (just before 4)
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
    
        // Break link to last node (defensive step)
        // Now second last node becomes last logically
        temp->next = nullptr;
    
        // Delete actual last node using tail pointer
        delete tail;
    
        // Update tail to new last node
        tail = temp;
    }

 /*
     * Function: print
     * Purpose: Traverse and display the linked list
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void print(){
        Node * temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

int main() {

    List ll;
    cout<<"Before pop back:\n";
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print();

    cout<<"After pop back:\n";
    ll.pop_back();
    ll.print();

    return 0;
}
