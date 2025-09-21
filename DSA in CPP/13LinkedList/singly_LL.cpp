#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }

};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void print(){ 
        Node* temp = head;
        cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << "]"<<endl;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        
        newNode->next = head; // same as (*newNode).next = head;
        head = newNode;
        return;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        return;
    }
    int pop_front(){
        if (head == NULL)
        {
            cout << "Empty!"<<endl;
            return -1;
        }
        
        Node* temp = head;
        head = head->next;

        if(head == NULL) tail = NULL;

        int data = temp->data;
        delete temp; //deletes dynamically allocated memory
        return data;
    }
    int pop_back(){
        if (head == NULL)
        {
            cout << "Empty!"<<endl;
            return -1;
        }
        if(head == tail){
            int data = head->data;
            delete head;
            head = tail = NULL;
            return data;
        }

        Node* temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        int data = tail->data;
        delete tail;
        tail = temp;
        temp->next = NULL;
        return data;
    }

    void insert_at(int val, int idx){
        
        if (idx == 0)
        {
            push_front(val);
            return;
        }
        
        Node* temp = head;
        for(int i = 0; i < idx-1; i++)
        {
            if(temp == NULL){
                cout<< "invalid"<<endl;
                return;
            }
            temp = temp->next;
            
        }
        if (temp == NULL)
        {
            return;
        }
        
        
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp == tail) tail = newNode;
        return;
        
    } 

    int search(int val){
        if (head == NULL)
        {
            return -1;
        }
        int i = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return i;
            }
            temp = temp->next;
            i++;
            
        }
        return -1;      
    }
};

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(4);
    cout << l1.pop_front()<<endl;
    cout << l1.pop_back()<<endl;
    l1.insert_at(5, 1);
    l1.print();
    cout << l1.search(6) << endl;

    return 0;
}