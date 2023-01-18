class Item{

};

class Node{
    public:
        Item item;
        Node* ptr;

        Node(Item _item){
            item = _item;
        }
};

class RefStack{
    Node* headptr = nullptr;

    bool isEmpty(){
        return headptr == nullptr;
    }

    void Push(Item item){
        Node node = Node(item);
        node.ptr = headptr;
        headptr = &node;
    }

    Item Pop(){
        Item val = headptr->item;
        headptr = headptr->ptr;
        return val;
    }
};

class RefQueue{
    Node* headptr = nullptr;

    bool isEmpty(){
        return headptr == nullptr;
    }

    void Enqueue(Item item){
        Node node = Node(item);
        node.ptr = headptr;
        headptr = &node;
    }

    Item Dequeue(){
        if(isEmpty()){
            //Error
        }else{
            Node* node = headptr;
            Node* prev;
            while (node->ptr != nullptr){
                prev = node;
                node = node->ptr;
            }
            Item val = node->item;
            prev->ptr = nullptr;
            return val;
        }
    }
};

class ArrayStack{
    int top = -1;
    int n = 10;
    Item stack[10];

    bool isEmpty(){
        return top < 0;
    }

    void Push(Item item){
        if (top >= n-1){
            //Error
        }else{
            top++;
            stack[top] = item;
        }
    }

    Item Pop(){
        if (isEmpty()){
            //Error
        }else{
            top--;
            return stack[top+1];
        }
    }
};

class ArrayQueue{
    int end = -1;
    int n = 10;
    Item queue[10];

    bool isEmpty(){
        return end < 0;
    }

    void Enqueue(Item item){
        if (end >= n-1){
            //Error
        }else{
            end++;
            queue[end] = item;
        }
    }

    Item Dequeue(){
        if (isEmpty()){
            //Error
        }else{
            Item val = queue[0];
            for(int i = 1; i++; i <= end){
                queue[i-1] = queue[i];
            }
            end--;
            return val;
        }
    }
};

int main(){
    
}