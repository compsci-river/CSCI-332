//CSCI 332
//River Sheppard
//1-13-2023
//
//I did this in a very weird way, it is a reference based structure, and I use the existance of a link to test if the word is valid. I set this up with nodes that have
//the potential to link to 27 more nodes, this gives a spot for a-z and then a position to signify the end of the word. To load the structure words are turned into an
//array of ints, with 0 signifying a, 25 signifying z, and 26 signifying the end of the word. Then in the head node we go to the array position of the first character
// and follow the pointer if there is one, if not we create a new node and point to it in that location. now we are on a secondary node and we go to the location of the
//character, we then repeat previous steps until the end of the character array, then repeat with all other words. This makes checking the words really easy as we just
//follow the pointers indicated by the characters, and as long as there are pointers all the way through the word it is in the spellchecker.
//
//I might have made this overly complex, and I don't really know how to check efficiency on it (I think it scales on word length, not number of words, but I am not sure)
//but I didn't want to just do what we were talking about in class, I wanted to at least try for something more complex, and it works!

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Node class, the value part not really important, it keeps track of what character the node is representing, but it is never used in the code, I just briefly used it
//while testing, on the other hand the array of pointers is what makes everything work so it is very important
class Node{
    public:
        int value;
        Node* nextLetter[27] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
                                NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
                                NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

        //constructor, yay!
        Node(int val){
            value = val;
        }
};

class SpellChecker{
    //Head pointer
    Node* firstLetter;

    //reads through the given text file line by line, and feeds the words from the lines into the AddWord function
    bool Load(string fName){
        bool success = true;
        fstream newFile;
        newFile.open(fName, ios::in);
        string temp;
        if (newFile.is_open()){
            while(getline(newFile,temp)){
                if (!AddWord(temp)){
                    cout << temp << " failed to be added to dictionary" << endl;
                    success = false;
                }
            }
            newFile.close();
        }
        return success;
    }

    //converts words into an integer array based on their ascii numbers and then sends array to the recursive AddChars function
    bool AddWord(string word){
        int length = word.length() + 1;
        int chars[length];

        for (int i = 0; i < word.length(); i++)
        {
            chars[i] = word[i] - 97;
        }

        chars[word.length()] = 26;

        return AddChars(chars, firstLetter, 0, length);
    }

    //Checks to see if the previous node has a pointer in the location of the current character, if it does it goes to that pointer with the next character if not it 
    //creates a new pointer in that location and goes to the new pointer with the next character, recurses until it has worked through all the characters of the word
    bool AddChars(int* chars, Node* node, int n, int length){
        if (n >= length){
            return true;
        } else if (node->nextLetter[chars[n]] != NULL){
            return AddChars(chars, node->nextLetter[chars[n]], n+1, length);
        } else {
            Node* newNode = new Node(chars[n]);
            node->nextLetter[chars[n]] = newNode;
            return AddChars(chars, newNode, n+1, length);
        }
        return false;
    }

    //controls the user input, and the output from the spellchecker
    void RunSpellChecker(){
        bool running = true;
        while (running){
            cout << "Enter a word to spellcheck, or type 'Q' to quit. \t";
            string temp;
            cin >> temp;
            cout << endl;
            if (temp == "Q"){
                running = false;
            } else {
                bool check = TestWord(temp);
                if (check) {
                    cout << temp << " is a word." << endl << endl;
                } else {
                    cout << temp << " is not a word, maybe you misspelled it." << endl << endl;
                }
            }
        }
        cout << "Thank you for your time." << endl;
    }

    //converts words into an integer array based on their ascii numbers and then sends array to the recursive TestChars function, this is basically the same as the
    //AddWord function, although there is some checking for user error (I would add more if I were to really release this)
    bool TestWord(string word){
        int length = word.length() + 1;
        int chars[length];

        for (int i = 0; i < word.length(); i++)
        {
            chars[i] = word[i]-97;
            //This is a very basic fix for uppercase letters, not sure if there is a better way, couldn't find one for c++ without a library
            if (chars[i] < 0){
                chars[i] += 32;
            }
        }

        chars[word.length()] = 26;

        return TestChars(chars, *firstLetter, 0, length);
    }

    //Checks if there is a pointer in the current node where the character is suggesting, if there is it continues on to that pointer with the next character until it
    //reaches the length of the word, if at any point there is not a pointer in the specified location it means that the word is not in the spellchecker
    bool TestChars(int* chars, Node node, int n, int length){
        if (n >= length){
            return true;
        } else if (node.nextLetter[chars[n]] != NULL){
            return TestChars(chars, *node.nextLetter[chars[n]], n+1, length);
        } else {
            return false;
        }
    }

    public:
        //constructor, initializes the head node, and then loads the words, and runs the program
        SpellChecker(string fName){
            firstLetter = new Node(26);
            if (Load(fName)){
                cout << "Finished Loading." << endl;
                RunSpellChecker();
            } else {
                cout << "Load Failed." << endl;
            }
        }
};

//main function just constructs the spellchecker
int main()
{
    cout << "Starting up." << endl;
    SpellChecker checker = SpellChecker("Words.txt");
    cout << "All done." << endl;
}