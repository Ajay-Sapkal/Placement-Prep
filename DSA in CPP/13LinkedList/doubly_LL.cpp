#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = prev = NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;
public:
    DoublyList(){
        head = tail = NULL;
    }

    void print(){
        Node* temp = head;
        cout << "[ ";
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;   
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        
    }
    void pop_front(){

        if (head == NULL)
        {
            cout << "empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        
        if (head == NULL)
        {
            delete temp;
            head = tail = NULL;
            return;
        }
        
        head->prev = NULL;
        delete temp;
    }
    void pop_back(){
        if (head == NULL)
        {
            cout << "empty!" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail == NULL)
        {
            head = tail = NULL;
            delete temp;
            return;
        }
        
        tail->next = NULL;
        delete temp;
    }

};

int main()
{   
    DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.push_back(4);
    dll.pop_front();
    dll.pop_back();
    dll.pop_back();
    
    
    

    dll.print();

    return 0;
}