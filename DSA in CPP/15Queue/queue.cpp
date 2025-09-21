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

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = NULL;
    }

    bool empty(){
        return head == NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);

        if(empty()){
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if (empty())
        {
            cout<< "Queue is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;  
    }

    int front(){
        if (empty())
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Queue q;
    // queue<int> q;  // STL
    // deque<int> d;  // double ended queue, push_back, push_front, pop_back, pop_front, front, back
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}