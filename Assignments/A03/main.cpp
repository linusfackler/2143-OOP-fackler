///////////////////////////////////////////////////////////////////////////////
//
// Author:           Linus Fackler
// Email:            linus.fackler@iCloud.com
// Label:            A03
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2021
//
// Description:
//       This program creates a queue used as an array that allows the user to push
//       items to the rear/end of the list and pop (return) items from the beginning of
//       the list. As long as the array is not full, it can always push and pop items,
//       as there is an integer traversing from the front, to the rear of the list, and
//       then back to the front and the same thing again.
//
//
// Usage:
//      - Will read in items through the console.
//
// Files:
//      main.cpp    : driver program
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;


class CircularArrayQue {
private:
    int *Container;
    int Front;            // first item in queue
    int Rear;             // last item in queue
    int QueSize;          // items in the queue
    int CurrentSize;      // actual number of items currently in queue

    /**
     * Private : init
     *
     * Description:
     *      As new array is created, Front, Rear, and CurrentSize
     *      are set to 0 and QueSize is set to 0 (default constructor)
     *      or to the passed in int (non-default constructor)
     *
     * Params:
     *      int     :  array size
     *
     * Returns:
     *      Void, therefore returns nothing.
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }       // returns a bool depending on wether array is full or not

public:
    CircularArrayQue() {  // default constructor, size of array is 10
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);       // non-default constructor, size of array is set with parameter
    }


    /**
     * Public : Push
     *
     * Description:
     *      Puts passed-in-item in the array at spot Read, which is
     *      0 (if array empty) or next empty spot after an item.
     *      Increments Rear by 1 to move end of array, and increments
     *      CurrentSize by 1.
     *      If array is full, nothing changes except error messages is displayed
     *
     * Params:
     *      int     :  item to be pushed in array
     *
     * Returns:
     *      Void, therefore returns nothing.
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }


    /**
     * Public : Pop
     *
     * Description:
     *      Returns item at spot Front. From left to right the first item
     *      in the array. Then increments Front by 1 and decrements
     *      CurrentSize by 1.
     * Params:
     *      No parameter.
     *
     * Returns:
     *      Int temp: number to be popped out of array.
     */

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);



    /**
     * Public : printQ
     *
     * Description:
     *      Prints out Array.
     * Params:
     *      No parameter.
     *
     * Returns:
     *      Void, therefore returns nothing.
     */
    void printQ()
    {
      int n = 0;
      while (n < QueSize)
      {
        cout << Container[n];
        n++;
      }
    }
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);

    C1.Push(4);
    C1.Push(5);

    C1.printQ();

    // Test Test

}
