//
//
//CSCI 332
//River Sheppard
//1-20-2023
//
//Implementing a reference based stack and queue as well as an array besed stack and queue, I don't think this needs to be turned in so I'm not going to comment it
//also the couts do a pretty good job of discribing what is happening

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

struct RefStack{
    Node* headptr;

    bool isEmpty(){
        return headptr == NULL;
    }

    void Push(int x){
        cout << "Attempting reference stack push." << endl;
        Node* temp = new Node(x);
        temp->next = headptr;
        headptr = temp;
        cout << "Pushed: \t" << x << "." << endl;
    }

    int Pop(){
        cout << "Attempting reference stack pop." << endl;
        if(isEmpty()){
            //Error
            cout << "Error: stack is empty." << endl;
        }else{
            int x = headptr->data;
            headptr = headptr->next;
            cout << "Popped: \t" << x << "." << endl;
            return x;
        }
        return -1;
    }

    RefStack(){
        headptr = NULL;
    }
};

struct RefQueue{
    Node* headptr;
    Node* rearptr;

    bool isEmpty(){
        return headptr == NULL;
    }

    void Enqueue(int x){
        cout << "Attempting reference queue enqueue." << endl;
        Node* temp = new Node(x);
        if(isEmpty()){
            headptr = rearptr = temp;
        }else{
            rearptr->next = temp;
            rearptr = temp;
        }
        cout << "Enqueued: \t" << x << "." << endl;
    }

    int Dequeue(){
        cout << "Attempting reference queue dequeue." << endl;
        if(isEmpty()){
            //Error
            cout << "Error: queue is empty." << endl;
        }else{
            int x = headptr->data;
            headptr = headptr->next;
            if(isEmpty()){
                rearptr = NULL;
            }
            cout << "Dequeued: \t" << x << "." << endl;
            return x;
        }
        return -1;
    }
    RefQueue(){
        headptr = NULL;
        rearptr = NULL;
    }
};

struct ArrayStack{
    int top = -1;
    int n = 10;
    int stack[10];

    bool isEmpty(){
        return top < 0;
    }

    void Push(int x){
        cout << "Attempting array stack push." << endl;
        if (top >= n-1){
            //Error
            cout << "Error: stack is full." << endl;
        }else{
            top++;
            stack[top] = x;
            cout << "Pushed: \t" << x << "." << endl;
        }
    }

    int Pop(){
        cout << "Attempting array stack pop." << endl;
        if (isEmpty()){
            //Error
            cout << "Error: stack is empty." << endl;
        }else{
            int x = stack[top];
            top--;
            cout << "Popped: \t" << x << "." << endl;
            return x;
        }
        return -1;
    }
};

struct ArrayQueue{
    int end = -1;
    int n = 10;
    int queue[10];

    bool isEmpty(){
        return end < 0;
    }

    void Enqueue(int x){
        cout << "Attempting array queue enqueue." << endl;
        if (end >= n-1){
            //Error
            cout << "Error: queue is full." << endl;
        }else{
            end++;
            queue[end] = x;
            cout << "Enqueued: \t" << x << "." << endl;
        }
    }

    int Dequeue(){
        cout << "Attempting array queue dequeue." << endl;
        if (isEmpty()){
            //Error
            cout << "Error: queue is empty." << endl;
        }else{
            int x = queue[0];
            for(int i = 0; i++; i >= end){
                queue[i] = queue[i+1];
            }
            end--;
            cout << "Dequeued: \t" << x << "." << endl;
            return x;
        }
        return -1;
    }
};

int main(){
    RefStack rStack;
    RefQueue rQueue;
    ArrayStack aStack;
    ArrayQueue aQueue;

    rStack.Push(5);
    rQueue.Enqueue(5);
    aStack.Push(5);
    aQueue.Enqueue(5);

    rStack.Push(7);
    rQueue.Enqueue(7);
    aStack.Push(7);
    aQueue.Enqueue(7);

    rStack.Pop();
    rQueue.Dequeue();
    aStack.Pop();
    aQueue.Dequeue();


}