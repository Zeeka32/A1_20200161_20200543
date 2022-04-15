#include <iostream>
#include "Linked_List.cpp"

using namespace std;

int main (void) {
    LinkedList <int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    LinkedList<int>::Iterator I = myList.begin();
    myList.push_front(-1);
    myList.push_front(-2);
    myList.push_front(-3);
    myList.push_front(-4);
    cout << "Iterator is pointing to " << *I << endl;
    myList.insert(0,I);
    cout << myList;
    try {
        I--;
        myList.erase(I);
        cout << myList;
        I = myList.end();
        I--;
        cout << "Iterator is pointing to " << *I << endl;
        myList.erase(I);
    }
    catch (string dummy) {cout << dummy << endl;}
    cout << myList;
    LinkedList <int> myList3;
    myList3 = myList;
    cout << myList3 << endl;
    return 0;
}
