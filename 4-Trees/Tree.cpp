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
};

class RefTree{
    Node* root = NULL;

    bool isEmpty(){
        return root = NULL;
    }

    public:
        void add(int x){
            if(isEmpty()){
                root = new Node(x);
            }else{
                Node* prev;
                Node* cur = root;
                bool dir;
                while(cur != NULL){
                    prev = cur;
                    if(x < cur->data){
                        cur = cur->left;
                        dir = true;
                    }else if(x > cur->data){
                        cur = cur->right;
                        dir = false;
                    }else{
                        cout << x << "already exists in the tree." << endl;
                        return;
                    }
                }
                if(dir){
                    cur->left = new Node(x);
                }else{
                    cur->right = new Node(x);
                }
            }
        }

        void remove(int x){
            
        }
};