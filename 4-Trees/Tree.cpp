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

int main(){
    RefTree rtree;
    rtree.add(50);
    rtree.add(60);
    rtree.add(30);
    rtree.add(80);
    rtree.add(70);
    rtree.add(90);
    rtree.add(75);
    rtree.add(65);
    rtree.add(55);
    rtree.remove(60);
    rtree.add(70);
    rtree.remove(30);
    rtree.search(25);
    rtree.add(25);
    rtree.search(25);
    rtree.add(30);
    rtree.add(40);
    rtree.add(35);
    rtree.add(27);
    rtree.add(10);
    rtree.add(45);
    rtree.remove(30);
    rtree.add(62);
    rtree.add(60);
    rtree.add(52);
}