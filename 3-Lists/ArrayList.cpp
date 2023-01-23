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

class ArrayList{
    int end = -1;
    int n;
    int* ptr;

    bool isFull(){
        return end >= n-1;
    }

    void Resize(){
        if(isFull()){
            n = 2 * n;
            int temp[n];
            for(int i = 0; i <= end; i++){
                temp[i] = *(ptr + i);
            }
            ptr = temp;
        }/*else if(end < n/3 && n >= 20){
            n = n / 2;
            int temp[n];
            for(int i = 0; i <= end; i++){
                temp[i] = *(ptr + i);
            }
            ptr = temp;
        }*/
    }

    public:
        ArrayList(){
            ArrayList(10);
        }

        ArrayList(int _n){
            n = _n;
            int temp[_n];
            ptr = temp;
        }

        bool add(int x){
            end++;
            *(ptr + end) = x;
            Resize();
            return true;
        }

        void add(int x, int pos){
            if(pos > n-1){
                return;
            }
            end++;
            for(int i = end; i > pos; i--){
                *(ptr + i) = *(ptr + i - 1);
            }
            *(ptr + pos) = x;
            Resize();
        }

        void clear(){
            end = -1;
            n = 10;
            int temp[n];
            ptr = temp;
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
            return x;
        }

        bool removeObj(int x){
            int ind = indexOf(x);
            if(ind != -1){
                removeInd(ind);
                return true;
            }
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
            for(int i = 0; i <= end; i++){
                cout << *(ptr + i) << "\t";
            }
            cout << endl;
        }
};

int main(){
    ArrayList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.print();
    list.add(9,2);
    list.print();
    list.set(4,1);
    list.print();
    list.removeInd(0);
    list.print();
    list.add(7);
    list.set(3,2);
    list.print();
    list.add(7,3);
    list.print();
    list.removeObj(9);
    list.print();
}