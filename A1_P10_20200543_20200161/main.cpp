#include <iostream>
#include "Linked_List.cpp"

using namespace std;

int main (void) {
    LinkedList <int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    cout << "testing push back\n";
    cout << myList;

    myList.push_front(-1);
    myList.push_front(-2);
    myList.push_front(-3);
    myList.push_front(-4);
    cout << "\ntesting push front\n";
    cout << myList;

    LinkedList<int>::Iterator I = myList.begin();

    cout << "\nIterator is pointing at " << *I << endl;
    myList.insert(0,I);

    cout << "testing insert 0 at index 0\n";
    cout << myList << endl;
    try {
        I--;
        cout << "testing erase at index 0\n";
        myList.erase(I);
        cout << "Iterator is pointing at "<<*I << " after erase";
        I = myList.end();
        I--;
        cout << "\nIterator is pointing to " << *I << endl;
        cout << "testing erase at last index\n";
        myList.erase(I);
    }
    catch (string dummy) {
        cout << dummy << endl;
    }

    cout << myList;
    LinkedList <int> myList3;
    myList3 = myList;
    cout << myList3 << endl;
    return 0;
}

