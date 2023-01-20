//
//
//CSCI 332
//River Sheppard
//1-20-2023
//
//Uses a stack to check if a word is a palindrome

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//I just used my reference based stack from earlier in the week as my base, only needed to change the variable type from int to char
struct Node{
    char data;
    Node* next;

    Node(char x){
        data = x;
        next = NULL;
    }
};

struct RefStack{
    Node* headptr;

    bool isEmpty(){
        return headptr == NULL;
    }

    void Push(char x){
        //cout << "Attempting reference stack push." << endl;
        Node* temp = new Node(x);
        temp->next = headptr;
        headptr = temp;
        //cout << "Pushed: \t" << x << "." << endl;
    }

    char Pop(){
        //cout << "Attempting reference stack pop." << endl;
        if(isEmpty()){
            //Error
            //cout << "Error: stack is empty." << endl;
        }else{
            char x = headptr->data;
            headptr = headptr->next;
            //cout << "Popped: \t" << x << "." << endl;
            return x;
        }
        return 0;
    }

    RefStack(){
        headptr = NULL;
    }
};

//where the magic happens, could use some error checking currently uppercase letters would mess stuff up, and there is no dictionary of words, so it is only checking that
//characters are reversible, not if it is a word
bool TestWord(string word){
    RefStack stack;
    int num = int(word.length()/2);
    //adds the first half of the word to a stack, rounded down if the word is uneven in length
    for(int i = 0; i < num; i++){
        stack.Push(word[i]);
    }
    //compares the top of the stack (by popping it) with the next character in the word (starts after the halfway point)
    for(int i = word.length()-num; i < word.length(); i++){
        if(stack.Pop() != word[i]){
            return false;
        }
    }
    return true;
}

//just a loop to keep from restarting the program for each word you want to check
int main(){
    bool running = true;
    while(running){
        cout << "Enter a word to check if it is a palindrome, or 'Q' to quit. \t";
        string temp;
        cin >> temp;
        cout << endl;
        if (temp == "Q"){
            running = false;
        } else {
            if (TestWord(temp)) {
                cout << temp << " is a palindrome." << endl << endl;
            } else {
                cout << temp << " is not a palindrome." << endl << endl;
            }
        }
    }
}