//
//
//CSCI 332
//River Sheppard
//1-13-2023
//
//Implements an array list from java, with all the functions that intails. I finished this weeks ago and have been trying to come up with the motivation to fully comment
//my work, today(2/15/2023) I decided I don't have that motivation so here you go.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class ArrayList{
    int end = -1;
    int n;
    int* ptr;

    //checks if the array in its current size is full
    bool isFull(){
        return end >= n-1;
    }

    //doubles n creates a new array of size n, transfers all the items from the old array into the new array, and then moves the pointer to the new array
    void Resize(){
        n = 2 * n;
        int* temp = new int[n];
        for(int i = 0; i <= end; i++){
            temp[i] = *(ptr + i);
        }
        delete ptr;
        ptr = temp;
    }

    public:
        //default constructor
        ArrayList(){
            ArrayList(10);
        }

        //constuctor with array size of _n
        ArrayList(int _n){
            n = _n;
            int* temp = new int[_n];
            ptr = temp;
        }

        //adds item at the end of the array by incrementing the index of the end by one and setting the point of the array referenced by the new end value equal to the
        //input value, then it checks if the array is now full and resizes it if it is
        bool add(int x){
            if(isFull()){
                Resize();
            }
            end++;
            *(ptr + end) = x;
            cout << "Adding:\t" << x << endl;
            print();
            return true;
        }

        //similar to the previous one, except it adds it to a middle point in the array and shifts everything after it over. then checks if it is full and resizes if needed
        void add(int x, int pos){
            if(isFull()){
                Resize();
            }
            if(pos > n-1){
                return;
            }
            end++;
            for(int i = end; i > pos; i--){
                *(ptr + i) = *(ptr + i - 1);
            }
            *(ptr + pos) = x;
            cout << "Adding:\t" << x << "\tAt:\t" << pos << endl;
            print();
        }

        //creates a new array and points to it instead of the old one
        void clear(){
            end = -1;
            n = 10;
            int* temp = new int[n];
            delete ptr;
            ptr = temp;
            cout << "Clearing array." << endl;
            print();
        }

        //Checks if the list contains the given value, returns true if it runs into the value, returns false if it reads all of the values and the searched value
        //is not present
        bool contains(int x){
            for(int i = 0; i <= end; i++){
                if(*(ptr + i) == x){
                    return true;
                }
            }
            return false;
        }

        //Resizes the array to ensure it is capable of fitting _n values
        void ensureCapacity(int _n){
            if(n < _n){
                n = _n;
                int temp[n];
                for(int i = 0; i <= end; i++){
                    temp[i] = *(ptr + i);
                }
                ptr = temp;
            }
        }

        //returns the item at the given position
        int get(int pos){
            return *(ptr + pos);
        }

        //returns the index of the first instance of the searched for item
        int indexOf(int x){
            for(int i = 0; i <= end; i++){
                if(*(ptr + i) == x){
                    return i;
                }
            }
            return -1;
        }

        bool isEmpty(){
            return end <= -1;
        }

        int lastIndexOf(int x){
            for(int i = end; i >= 0; i--){
                if(*(ptr + i) == x){
                    return i;
                }
            }
            return -1;
        }

        int removeInd(int pos){
            int x = *(ptr + pos);
            end--;
            for(int i = pos; i <= end; i++){
                *(ptr + i) = *(ptr + i + 1);
            }
            cout << "Removing:\t" << x << "\tAt:\t" << pos << endl;
            print();
            return x;
        }

        bool removeObj(int x){
            int pos = indexOf(x);
            if(pos != -1){
                removeInd(pos);
                cout << "Removing:\t" << x << "\tAt:\t" << pos << endl;
                print();
                return true;
            }
            cout << "Attempted to Remove:\t" << x << "\tNot Found." << endl;
            print();
            return false;
        }

        void removeRange(int fromInd, int toInd){
            for(int i = fromInd; i < toInd; i++){
                removeInd(i);
            }
        }

        int set(int x, int pos){
            int temp = *(ptr + pos);
            *(ptr + pos) = x;
            return temp;
        }

        int size(){
            return n;
        }

        ArrayList* sublist(int fromInd, int toInd){
            ArrayList* tempList = new ArrayList();
            for(int i = fromInd; i < toInd; i++){
                tempList->add(*(ptr + i));
            }
            cout << "Created sublist from:\t" << fromInd << "\tto:\t" << toInd << endl;
            tempList->print();
            return tempList;
        }

        int* toArray(){
            int* temp = new int[end+1];
            for(int i = 0; i <= end; i++){
                temp[i] = *(ptr + i);
            }
            return temp;
        }

        void trimToSize(){
            n = end + 1;
            int* temp = new int[n];
            for(int i = 0; i <= end; i++){
                temp[i] = *(ptr + i);
            }
            delete ptr;
            ptr = temp;
        }

        void print(){
            cout << "[";
            if(!isEmpty()){
                cout << *ptr;
                for(int i = 1; i <= end; i++){
                    cout << ", " << *(ptr + i);
                }
            }
            cout << "]" << endl;
        }
};

int main(){
    ArrayList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9,2);
    list.print();
    list.set(4,1);
    list.removeInd(0);
    list.add(7);
    list.set(3,2);
    list.add(7,3);
    list.removeObj(9);
    list.clear();
    list.add(0);
    list.add(1);
    list.add(3);
    list.add(4);
    list.add(6);
    list.add(2,2);
    list.add(5,5);
    ArrayList sub = *list.sublist(3,5);
    sub.add(9);
}