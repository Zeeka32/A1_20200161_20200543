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

    cout << "Test OK\n";

    myList.push_front(-1);
    myList.push_front(-2);
    myList.push_front(-3);
    myList.push_front(-4);
    cout << "\ntesting push front\n";
    cout << myList;

    cout << "Test OK\n\n";

    LinkedList<int>::Iterator I = myList.begin();


    cout << "testing insert 0 at index 0\n";
    myList.insert(0,I);
    cout << myList;

    cout << "Test OK\n\n";

    cout << "testing insert 3 at index 4\n";
    I++; I++; I++; I++;
    myList.insert(3,I);
    cout << myList;

    cout << "Test OK\n\n";

    //cout << "testing insert 3 at out of range index\n";
    //I++; I++; I++; I++; I++; I++; I++;
    //myList.insert(3,I);
    //cout << myList;

    //cout << "Test OK\n\n";

    try {
        I = myList.begin();
        cout << "testing erase at index 0\n";
        myList.erase(I);
        cout << myList;

        cout << "Test OK\n\n";

        cout << "testing erase at index 5\n";
        I = myList.begin();
        I++; I++; I++; I++; I++;
        myList.erase(I);
        cout << myList;

        cout << "Test OK\n\n";

        I = myList.end();
        I--;
        cout << "testing erase at last index\n";
        myList.erase(I);
        cout << myList;

        cout << "Test OK\n\n";
    }
    catch (string dummy) {
        cout << dummy << endl;
    }

    cout << "testing assignment operator\n";
    LinkedList <int> myList3;
    myList3 = myList;
    cout << myList3;

    cout << "Test OK\n\n";
    return 0;
}

