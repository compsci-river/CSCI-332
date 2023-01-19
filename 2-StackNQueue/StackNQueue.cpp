#include <iostream>

using namespace std;


class Item{
    int item;

    public:
        Item(){
            item = -1;
        }
        Item(int _item){
            item = _item;
        }

        int get(){
            return item;
        }
};

class Node{
    public:
        Item item;
        Node* ptr;

        Node(Item _item){
            item = _item;
            ptr = NULL;
        }
};

class RefStack{
    Node* headptr = NULL;

    bool isEmpty(){
        return headptr == NULL;
    }

    public:
        void Push(Item item){
            Node node = Node(item);
            node.ptr = headptr;
            headptr = &node;
        }

        Item Pop(){
            if(isEmpty()){
                //Error
                cout << "Stack is empty." << endl;
            }else{
                Item val = headptr->item;
                headptr = headptr->ptr;
                return val;
            }
            return Item();
        }
};

class RefQueue{
    Node* headptr = NULL;
    Node* rearptr = NULL;

    bool isEmpty(){
        return headptr == NULL;
    }

    public:
        void Enqueue(Item item){
            Node node = Node(item);
            node.ptr = headptr;
            if(isEmpty()){
                rearptr = &node;
            }
            headptr = &node;
        }

        Item Dequeue(){
            if(isEmpty()){
                //Error
                cout << "Queue is empty." << endl;
            }else{
                Node* node = headptr;
                Node* prev;
                while (node != rearptr){
                    prev = node;
                    node = node->ptr;
                }
                Item val = node->item;
                prev->ptr = NULL;
                rearptr = prev;
                return val;
            }
            return Item();
        }
};

class ArrayStack{
    int top = -1;
    int n = 10;
    Item stack[10];

    bool isEmpty(){
        return top < 0;
    }

    public:
        void Push(Item item){
            if (top >= n-1){
                //Error
                cout << "Stack is full." << endl;
            }else{
                top++;
                stack[top] = item;
            }
        }

        Item Pop(){
            if (isEmpty()){
                //Error
                cout << "Stack is empty." << endl;
            }else{
                top--;
                return stack[top+1];
            }
            return Item();
        }
};

class ArrayQueue{
    int end = -1;
    int n = 10;
    Item queue[10];

    bool isEmpty(){
        return end < 0;
    }

    public:
        void Enqueue(Item item){
            if (end >= n-1){
                //Error
                cout << "Queue is full." << endl;
            }else{
                end++;
                queue[end] = item;
            }
        }

        Item Dequeue(){
            if (isEmpty()){
                //Error
                cout << "Queue is empty." << endl;
            }else{
                Item val = queue[0];
                for(int i = 1; i++; i <= end){
                    queue[i-1] = queue[i];
                }
                end--;
                return val;
            }
            return Item();
        }
};

int main(){
    RefStack rStack;
    RefQueue rQueue;
    ArrayStack aStack;
    ArrayQueue aQueue;

    rStack.Push(Item(5));
    rQueue.Enqueue(Item(5));
    aStack.Push(Item(5));
    aQueue.Enqueue(Item(5));

    rStack.Push(Item(7));
    rQueue.Enqueue(Item(7));
    aStack.Push(Item(7));
    aQueue.Enqueue(Item(7));

    cout << "Popping the reference stack gets: \t" << rStack.Pop().get() << endl;
    cout << "Dequeueing the reference queue gets: \t" << rQueue.Dequeue().get() << endl;
    cout << "Popping the array stack gets: \t" << aStack.Pop().get() << endl;
    cout << "Dequeueing the array queue gets: \t" << aQueue.Dequeue().get() << endl << endl;


}