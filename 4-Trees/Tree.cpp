//
//
//CSCI 332
//River Sheppard
//1-13-2023
//
//
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int _data){
        data = _data;
    }

    bool hasLeftChild(){
        return left != NULL;
    }

    bool hasRightChild(){
        return right != NULL;
    }

    bool isInternal(){
        return hasLeftChild()||hasRightChild();
    }

    bool hasTwoChildren(){
        return hasLeftChild()&&hasRightChild();
    }
};

class RefTree{
    Node* root = NULL;

    bool isEmpty(){
        return root = NULL;
    }

    Node* add(int x, Node* node){
        if(node == NULL){
            cout << "Added " << x << " to the tree." << endl;
            return new Node(x);
        }else{
            if(x < node->data){
                node->left = add(x, node->left);
                return node;
            }else if(x > node->data){
                node->right = add(x, node->right);
                return node;
            }else{
                cout << x << " already exists in the tree." << endl;
                return node;
            }
        }
    }

    Node* remove(int x, Node* node){
        if(node == NULL){
            //if the recusion reaches a null node, then that means the value x does not exist within the tree
            cout << x << " does not exist in the tree." << endl;
            return NULL;
        }else{
            //Searching for the node of value x
            if(x < node->data){
                //Current node value is larger than x, continue search in left node
                node->left = remove(x, node->left);
                return node;
            }else if(x > node->data){
                //Current node value is smaller than x, continue search in right node
                node->right = remove(x, node->right);
                return node;
            }else{
                //Found the node of value x, onto deleting it
                if(node->isInternal()){
                    if(node->hasTwoChildren()){
                        //if the node has two children then it must be replaced by the leftmost descendant of the right child (could also do the rightmost descendant of the
                        //left child, but the methods are equal so it didn't matter which one I picked.)
                        Node* prev = node->right;
                        Node* cur = node->right;
                        while(cur->left != NULL){
                            prev = cur;
                            cur = cur->left;
                        }
                        if(cur != prev){
                            prev->left = cur->right;
                            cur->right = node->right;
                        }
                        cur->left = node->left;
                        delete node;
                        cout << "Removed " << x << " from the tree." << endl;
                        return cur;
                    }else{
                        //if the node only has one child than the child just gets moved into its spot
                        if(node->hasLeftChild()){
                            Node* left = node->left;
                            delete node;
                            cout << "Removed " << x << " from the tree." << endl;
                            return left;
                        }else{
                            Node* right = node->right;
                            delete node;
                            cout << "Removed " << x << " from the tree." << endl;
                            return right;
                        }
                    }
                }else{
                    //If the node is external it just needs to be deleted and return null so there is no longer a pointer to it.
                    delete node;
                    cout << "Removed " << x << " from the tree." << endl;
                    return NULL;
                }
            }
        }
    }

    bool search(int x, Node* node){
        if(node == NULL){
            //if the recusion reaches a null node, then that means the value x does not exist within the tree
            cout << x << " does not exist in the tree." << endl;
            return false;;
        }else{
            //Searching for the node of value x
            if(x < node->data){
                //Current node value is larger than x, continue search in left node
                return search(x, node->left);
            }else if(x > node->data){
                //Current node value is smaller than x, continue search in right node
                return search(x, node->right);
            }else{
                //Found the node of value x
                cout << "Found " << x << endl;
                return true;
            }
        }
    }

    void print(Node* node, int space){
        if(node == NULL){
            return;
        }else{
            space++;
            print(node->left,space);
            for(int i = 0; i < space; i++){
                cout << "\t";
            }
            cout << node->data << endl;
            print(node->right,space);
        }
    }

    public:
        void add(int x){
            cout << "Attempting to add " << x << " to the tree." << endl;
            root = add(x, root);
            print();
        }

        void remove(int x){
            cout << "Attempting to remove " << x << " from the tree." << endl;
            root = remove(x, root);
            print();
        }

        bool search(int x){
            cout << "Searching for " << x << " in the tree" << endl;
            return search(x, root);
        }

        void print(){
            print(root, 0);
        }
};

class ArrayTree{
    int n = 100;
    int tree[100];

    int left(int i){
        return 2 * i + 1;
    }

    int right(int i){
        return 2 * i + 2;
    }

    bool hasLeftChild(int i){
        int left = 2 * i + 1;
        if(left >= n){
            return false;
        }
        return tree[left] != NULL;
    }

    bool hasRightChild(int i){
        int right = 2 * i + 2;
        if(right >= n){
            return false;
        }
        return tree[right] != NULL;
    }

    bool isInternal(int i){
        return hasLeftChild(i)||hasRightChild(i);
    }

    bool hasTwoChildren(int i){
        return hasLeftChild(i)&&hasRightChild(i);
    }

    public:
        ArrayTree(){
            fill_n(tree, 100, NULL);
        }

        bool add(int x){
            int i = 0;
            while(tree[i] != NULL){
                if(x < tree[i]){
                    i = left(i);
                }else if(x > tree[i]){
                    i = right(i);
                }else{
                    cout << x << " already exists in the tree." << endl;
                    return false;
                }
                if(i >= n){
                    cout << "There is no room for " << x << " in the tree." << endl;
                }
            }
            tree[i] = x;
            cout << "Added " << x << " to the tree." << endl;
            return true;
        }

        bool remove(int x){
            int i = 0;
            while(tree[i] != x){
                if(x < tree[i]){
                    i = left(i);
                }else if(x > tree[i]){
                    i = right(i);
                }
                if(i >= n){
                    cout <<  x << " is not in the tree." << endl;
                }
            }
            if(isInternal(i)){
                if(hasTwoChildren(i)){
                    //if the node has two children then it must be replaced by the leftmost descendant of the right child (could also do the rightmost descendant of the
                    //left child, but the methods are equal so it didn't matter which one I picked.)
                    int iPrev = right(i);
                    int iCur = right(i);
                    while(tree[left(iCur)] != NULL){
                        iPrev = iCur;
                        iCur = left(iCur);
                    }
                    tree[i] = tree[iCur];
                    while(tree[right(iCur)] != NULL){
                        
                    }
                    /*
                    if(iCur != iPrev){
                        prev->left = cur->right;
                        cur->right = node->right;
                    }
                    cur->left = node->left;
                    delete node;
                    cout << "Removed " << x << " from the tree." << endl;
                    return cur;*/
                }else{
                    //if the node only has one child than the child just gets moved into its spot
                    if(hasLeftChild(i)){
                        tree[i] = tree[2 * i + 1];
                        tree[2 * i + 1] = NULL;
                        cout << "Removed " << x << " from the tree." << endl;
                        return true;
                    }else{
                        tree[i] = tree[2 * i + 2];
                        tree[2 * i + 2] = NULL;
                        cout << "Removed " << x << " from the tree." << endl;
                        return true;
                    }
                }
            }else{
                //If the node is external it just needs to be deleted and return null so there is no longer a pointer to it.
                tree[i] == NULL;
                cout << "Removed " << x << " from the tree." << endl;
                return true;;
            }
        }
};

void loop(){
    bool running = true;
    while(running){
        cout << "Enter 'R' to create a reference tree, 'A' to create an array tree, or 'Q' to quit:\t";
        string tem;
        cin >> tem;
        if(tem == "Q"){
            running = false;
            cout << "Quitting..." << endl;
        }else if(tem == "R"){
            RefTree rtree;
            while(running){
                cout << "Enter 'A' to add a number to the tree, 'D' to delete a number from the tree, or 'Q' to quit:\t";
                string temp;
                cin >> temp;
                if(temp == "A"){
                    cout << "What number would you like to add to the tree:\t";
                    string tempo;
                    cin >> tempo;
                    rtree.add(stoi(tempo));
                }else if(temp == "D"){
                    cout << "What number would you like to remove from the tree:\t";
                    string tempo;
                    cin >> tempo;
                    rtree.remove(stoi(tempo));
                }else if(temp == "Q"){
                    running = false;
                    cout << "Quitting..." << endl;
                }else{
                    cout << "Let's try again." << endl;
                }
            }
        }else if(tem == "A"){

        }else{
            cout << "Let's try again." << endl;
        }
    }
}

int main(){
    loop();
}