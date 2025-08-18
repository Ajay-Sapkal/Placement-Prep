#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Circular_queue{
    int* arr;
    int currsize, cap;
    int f, r;

public:
    Circular_queue(int size){
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
        currsize = 0;
    }

    bool empty(){
        return currsize == 0;
    }

    void push(int data){
        if (currsize == cap)
        {
            cout << "CQ is full\n";
            return;
        }

        r = (r+1)%cap;
        arr[r] = data;
        currsize++;
    }

    void pop(){
        if (empty())
        {   
            cout << "empty" << endl;
        }
        else
        {
            f = (f+1) % cap;
            currsize--;
        }
        
    }

    int front(){
        if (empty())
        {   
            cout << "empty" << endl;
            return -1;
        }
        return arr[f];
    }

    void print_arr(){
        for (int i = 0; i < cap; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }

};

int main()
{
    Circular_queue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.pop();
    cq.push(4);

    cq.print_arr(); 

    while (!cq.empty())
    {
        cout<< cq.front() << " ";
        cq.pop();
    }
    cout << endl;


    return 0;
}