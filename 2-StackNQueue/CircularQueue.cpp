#include <iostream>

using namespace std;

struct CirQueue{
    int front;
    int rear;
    int n = 10;
    int queue[10];

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (front == rear + 1) || (front == 0 && rear == n - 1);
    }

    void Enqueue(int x){
        cout << "Attempting circular queue enqueue." << endl;
        if(isFull()){
            //Error
            cout << "Error: queue is full." << endl;
        }else{
            rear = (rear + 1) % n;
            queue[rear] = x;
            if(isEmpty()){
                front++;
            }
            cout << "Enqueued: \t" << x << endl << "At Index: \t" << rear << endl;
        }
    }

    int Dequeue(){
        cout << "Attempting circular queue dequeue." << endl;
        if(isEmpty()){
            //Error
            cout << "Error: queue is empty." << endl;
            return -1;
        }else{
            int x = queue[front];
            cout << "Dequeued: \t" << x << endl << "At Index: \t" << front << endl;
            if(front == rear){
                front = -1;
                rear = -1;
            }else{
                front = (front + 1) % n;
            }
            return x;
        }
    }

    CirQueue(){
        front = -1;
        rear = -1;
        cout << "Created Circular Queue." << endl;
    }
};

int main(){
    CirQueue cQueue;
    cQueue.Enqueue(5);
    cQueue.Enqueue(7);
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Enqueue(1);
    cQueue.Enqueue(2);
    cQueue.Enqueue(3);
    cQueue.Enqueue(4);
    cQueue.Enqueue(5);
    cQueue.Enqueue(6);
    cQueue.Enqueue(7);
    cQueue.Enqueue(8);
    cQueue.Enqueue(9);
    cQueue.Enqueue(10);
    cQueue.Enqueue(11);
    cQueue.Dequeue();
}