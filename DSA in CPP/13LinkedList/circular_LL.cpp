#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Circular_list{
    Node* head;
    Node* tail;

public:
    Circular_list(){

        head = tail = NULL;
    }

    void print(){
        if (head == NULL)
        {
            cout << "empty!" << endl;
            return;
        }
        
        Node* temp = head;
        cout << "[ ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "]" << endl;
    }
    void insert_at_head(int val){
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
        
    }

    void insert_at_tail(int val){
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        
    }

    void delete_at_head(){
        if (head == NULL)
        {
            cout << "empty!" << endl;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void delete_at_tail(){
        if (head == NULL )
        {
            cout << "empty!" << endl;
        }
        else if (head == tail)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Node* temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;

        }
        
        
        
    }

};


int main()
{
    Circular_list l;
    l.insert_at_head(1);
    l.insert_at_head(2);
    l.insert_at_head(3);
    l.insert_at_tail(4);

    l.delete_at_head();
    l.delete_at_tail();
    

    l.print();
    return 0;
}