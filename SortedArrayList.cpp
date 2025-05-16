#include <iostream>
#include <cmath>

using namespace std;

/*

Array
- Unsorted
- Sorted

Linked List
- UnSorted
- Sorted


int LengthIs();

bool IsFull();
bool IsEmpty();

void InsertItem(); -- 
void DeleteItem(); -- 
void RetrieveItem(); -- 

void MakeEmpty();

bool IsLastItem();
void GetNextItem();
void ResetList();

void Display();

-> 4
0 1 2 3 4 5 6
1 2 3 4 5 6   

*/

const int MAX_SIZE = 500;

template <class T>
class SortedArrayList {
private:
    T items[MAX_SIZE];
    int length;
    int currentPos;
public:
    SortedArrayList() {
        length = 0;
        currentPos = -1;
    }

    bool IsFull() const {
        return length >= MAX_SIZE;
    }

    bool IsEmpty() {
        return length == 0;
    }

    void InsertItem(T item) {
        if (IsFull()) {
            cout << "List is full!!" << endl;
            return;
        }

        int location = 0;
        while (location < length && items[location] < item) {
            location++;
        }

        if (location < length) {
            for (int index = length; index > location; index--) {
                items[index] = items[index - 1];
            }
        }

        items[location] = item;
        length++;
    }

    void DeleteItem(T item){
        if (IsEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        int location = 0;
        while (location < length && items[location] != item) {
            location++;
        }

        if (location < length) {

            for (int index = location + 1; index < length; index++) {
                items[index - 1] = items[index];
            }

            length--;
        }
    }

    void RetrieveItem(T &item, bool &found){
        // Linear Search
        found = false;
        int lcoation = 0;
        while (lcoation < length && !found) {
            if (item > items[lcoation]) {
                lcoation++;
            }
            else if (item < items[lcoation]) {
                lcoation = length;
            }
            else {
                found = true;
                item = items[lcoation];
            }
        }
    }
    
    void RetrieveItem2(T &item, bool &found){
        // Binary Search
        found = false;
        int midPoint, first = 0, last = length - 1;
        while(first <= last) {
            midPoint = (first + last) / 2;
            if (item < items[midPoint]) {
                last = midPoint - 1;
            }
            else if (item > items[midPoint]) {
                first = midPoint + 1;
            }
            else {
                found = true;
                item = items[midPoint];
                break;
            }
        }
    }

    void MakeEmpty() {
        length = 0;
    }

    bool IsLastItem() {
        return currentPos >= (length - 1);
    }

    void GetNextItem(T &item){
        if (IsLastItem()) {
            cout << "No more items left!" << endl;
            return;
        }

        item = items[++currentPos];
    }

    void ResetList() {
        currentPos = -1;
    }

    void Display() {
        ResetList();
        T item;
        cout << "[ ";
        while (!IsLastItem()) {
            GetNextItem(item);
            cout << item << " ";
        }
        cout << "]";
    }

    int Sum() {
        int result = 0;
        for (int i = 0; i < length; i++) {
            result += items[i];
        }
        return result;
    }

};

int main()
{
    SortedArrayList<int> myList;
    myList.InsertItem(6);
    myList.InsertItem(5);
    myList.InsertItem(1);
    myList.InsertItem(3);
    myList.InsertItem(8);
    myList.Display();
    myList.DeleteItem(5);
    myList.Display();

    int item = 1;
    bool found;
    myList.RetrieveItem2(item, found);
    cout << (found ? "Item found" : "Item not found!");


}