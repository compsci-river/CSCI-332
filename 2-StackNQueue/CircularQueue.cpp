//
//
//CSCI 332
//River Sheppard
//1-20-2023
//
//Creates a circular queue using an array implementation

#include <iostream>

using namespace std;

struct CirQueue{
    int front;
    int rear;
    int n = 10;
    int queue[10];

    //checks if the queue is empty, this works because front is set to -1 when the queue is initialized, and when the last item is dequeued
    bool isEmpty(){
        return front == -1;
    }

    //checks if the queue fills the array, there are two scenarios where the queue fills the array either the front is at 0 and the rear is at the end of the array, or the
    //front is in the middle somewhere, and the rear has wrapped around to the position behind it
    bool isFull(){
        return (front == rear + 1) || (front == 0 && rear == n - 1);
    }

    //adds stuff to the queue
    void Enqueue(int x){
        cout << "Attempting circular queue enqueue." << endl;
        if(isFull()){
            //Error
            cout << "Error: queue is full." << endl;
        }else{
            //increments the rear while keeping it inside of the array
            rear = (rear + 1) % n;
            //adds x to the queue at the rear
            queue[rear] = x;
            //if the queue was empty sets the front to zero as well
            if(isEmpty()){
                front++;
            }
            cout << "Enqueued: \t" << x << "\tAt Index: \t" << rear << endl;
        }
    }

    int Dequeue(){
        cout << "Attempting circular queue dequeue." << endl;
        if(isEmpty()){
            //Error
            cout << "Error: queue is empty." << endl;
            return -1;
        }else{
            //stores the value to be dequeued
            int x = queue[front];
            cout << "Dequeued: \t" << x << "\tAt Index: \t" << front << endl;
            //if the queue will be empty after the dequeue resets the front and rear index to -1, otherwise increments the front index
            if(front == rear){
                front = -1;
                rear = -1;
            }else{
                front = (front + 1) % n;
            }
            //returns the value
            return x;
        }
    }

    //constructor!!!!
    CirQueue(){
        front = -1;
        rear = -1;
        cout << "Created Circular Queue." << endl;
    }
};

//Testing... Testing 1.. 2.. 3..
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
    cQueue.Enqueue(12);
    cQueue.Dequeue();
    cQueue.Enqueue(13);
    cQueue.Dequeue();
    cQueue.Enqueue(14);
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
    cQueue.Dequeue();
}