//
//
//CSCI 332
//River Sheppard
//1-13-2023
//
//Implements an array list from java, with all the functions that intails.
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
        int temp[n];
        for(int i = 0; i <= end; i++){
            temp[i] = *(ptr + i);
        }
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
            int temp[_n];
            ptr = temp;
        }

        //adds item at the end of the array by incrementing the index of the end by one and setting the point of the array referenced by the new end value equal to the
        //input value, then it checks if the array is now full and resizes it if it is
        bool add(int x){
            end++;
            *(ptr + end) = x;
            if(isFull()){
                Resize();
            }
            cout << "Adding:\t" << x << endl;
            print();
            return true;
        }

        //similar to the previous one, except it adds it to a middle point in the array and shifts everything after it over. then checks if it is full and resizes if needed
        void add(int x, int pos){
            if(pos > n-1){
                return;
            }
            end++;
            for(int i = end; i > pos; i--){
                *(ptr + i) = *(ptr + i - 1);
            }
            *(ptr + pos) = x;
            if(isFull()){
                Resize();
            }
            cout << "Adding:\t" << x << "\tAt:\t" << pos << endl;
            print();
        }

        //creates a new array and points to it instead of the old one
        void clear(){
            end = -1;
            n = 10;
            int temp[n];
            ptr = temp;
            cout << "Clearing array." << endl;
            print();
        }

        bool contains(int x){
            for(int i = 0; i <= end; i++){
                if(*(ptr + i) == x){
                    return true;
                }
            }
            return false;
        }

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

        int get(int pos){
            return *(ptr + pos);
        }

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

        ArrayList sublist(int fromInd, int toInd){
            ArrayList tempList;
            for(int i = fromInd; i < toInd; i++){
                tempList.add(*(ptr + i));
            }
            return tempList;
        }

        int* toArray(){
            int temp[end+1];
            for(int i = 0; i <= end; i++){
                temp[i] = *(ptr + i);
            }
            return temp;
        }

        void trimToSize(){
            int temp[end+1];
            for(int i = 0; i <= end; i++){
                temp[i] = *(ptr + i);
            }
            ptr = temp;
        }

        void print(){
            cout << "[";
            for(int i = 0; i <= end; i++){
                cout << *(ptr + i) << "\t";
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
    list.add(1);
    list.add(3);
    list.add(4);
    list.add(6);
    list.add(2,1);
    list.add(5,5);
}