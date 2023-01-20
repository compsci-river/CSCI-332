//
//
//CSCI 332
//River Sheppard
//1-20-2023
//
//Uses a stack to reverse the order of an array, and then does the same using a queue

#include <iostream>

using namespace std;

//Just used my array based stack and queue from earlier in the week
struct ArrayStack{
    int top = -1;
    int n = 10;
    int stack[10];

    bool isEmpty(){
        return top < 0;
    }

    void Push(int x){
        //cout << "Attempting array stack push." << endl;
        if (top >= n-1){
            //Error
            //cout << "Error: stack is full." << endl;
        }else{
            top++;
            stack[top] = x;
            //cout << "Pushed: \t" << x << "." << endl;
        }
    }

    int Pop(){
        //cout << "Attempting array stack pop." << endl;
        if (isEmpty()){
            //Error
            //cout << "Error: stack is empty." << endl;
        }else{
            int x = stack[top];
            top--;
            //cout << "Popped: \t" << x << "." << endl;
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
        //cout << "Attempting array queue enqueue." << endl;
        if (end >= n-1){
            //Error
            //cout << "Error: queue is full." << endl;
        }else{
            end++;
            queue[end] = x;
            //cout << "Enqueued: \t" << x << "." << endl;
        }
    }

    int Dequeue(){
        //cout << "Attempting array queue dequeue." << endl;
        if (isEmpty()){
            //Error
            //cout << "Error: queue is empty." << endl;
        }else{
            int x = queue[0];
            for(int i = 0; i< end; i++){
                queue[i] = queue[i+1];
            }
            end--;
            //cout << "Dequeued: \t" << x << "." << endl;
            return x;
        }
        return -1;
    }
};

//Just loops through the array to print it out in a nice format
void PrintArray(int ints[10]){
    cout << "[";
    for(int i = 0; i < 10; i++){
        cout << ints[i];
        if (i != 9){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


int main(){
    int ints[10];
    //Random fill array
    for(int i = 0; i < 10; i++){
        ints[i] = rand() % 25;
    }
    cout << "Initial Array: \t\t";
    PrintArray(ints);

    ArrayStack stack;
    //Stack reverse
    //loops through the array pushing the items to the stack
    for(int i = 0; i < 10; i++){
        stack.Push(ints[i]);
    }
    //loops through the array setting the value equal to the pop off the stack, because of the design of a stack this is all that is needed, last one on, first one off
    //reverses the order of items
    for(int i = 0; i < 10; i++){
        ints[i] = stack.Pop();
    }
    cout << "Reversed Array: \t";
    PrintArray(ints);

    ArrayQueue queue;
    //Queue reverse
    //loops through the array enqueueing the items
    for(int i = 0; i < 10; i++){
        queue.Enqueue(ints[i]);
    }
    //loops through the array setting the value equal to the item dequeued from the queue, because queues are used to keep the original order it needs to start at the back
    //of the array and work its way forward
    for(int i = 0; i < 10; i++){
        ints[9-i] = queue.Dequeue();
    }
    cout << "Re-reversed Array: \t";
    PrintArray(ints);
}