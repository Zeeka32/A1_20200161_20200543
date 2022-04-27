#include <iostream>
#include <genshin.h>
#include "Linked_List.cpp"

using namespace std;

int main (void) {
    LinkedList <string> characters;
    LinkedList<string>::Iterator I = characters.end();
    cout << "1-insert back 2-insert front 3-insert by place 4-control iterator" << endl;
    cout << "5-size 6-erase back 7-erase front 8-erase by place 9-insert/erase 10-print" << endl;
    cout << "Iterator is intialized to the begin........." << endl;
    while (true){
        int choice = 0;
        while (true){
            cout <<"coice >>";
            cin >> choice;
            if (choice <= 11 && choice >= 0){
                break;
            }
            cout << "retry.." << endl;
        }
        if (choice == 1){
            cout << "Name: ";
            string x;
            cin >> x;
            characters.push_back(x);
            cout << "content: [" << *I << ']' << endl;
        }
        else if (choice == 2){
            cout << "Name: ";
            string x;
            cin >> x;
            characters.push_front(x);
            cout << "content: [" << *I << ']' << endl;
        }
        else if (choice == 3){
            cout << "Name: ";
            string x;int y;
            cin >> x;
            cout << "place: "; cin >> y;
            I = characters.begin();
            for (int i = 0; i < y - 1; i++){
                I++;
            }
            characters.insert(x, I);
            cout << "content: [" << *I << ']' << endl;
        }
        else if (choice == 4){
            string choices;
            while (true){
                cout << "content: [" << *I << ']' << endl;
                if (choices == "no")
                    break;
                cout << "++ / --: ";
                cin >> choices;
                if (choices == "++"){
                    I++;
                }
                else {
                    I--;
                }
                cout << "resume? ";
                cin >> choices;
            }
        }
        else if (choice == 5){
            cout << "Linked List size is " << characters.size() << endl;
        }
        else if (choice == 6){
            characters.pop_back();
            cout << "content: [" << *I << ']' << endl;
        }
        else if (choice == 7){
            I++;
            characters.pop_front();//error 
            cout << "content: [" << *I << ']' << endl;
        }
        else if (choice == 8){
            cout << "place"; int x; cin >> x;
            I = characters.begin();
            for (int i = 0; i < x - 1; i++){
                I++;
            }
            try {
                characters.erase(I);
            }catch (string e){cout << e << endl;}
            cout << "content: [" << *I << ']' << endl;
        }
        else if (choice == 9){
            cout << "choose to insert or delete ";
            cin >> choice;
            if (choice == 1){
                cout << "Name: "; string x; cin >> x;
                characters.insert (x, I);
                cout << "content: [" << *I << ']' << endl;
            }else if (choice == 2){
            try {
                characters.erase(I);
            }catch (string e){cout << e << endl;}
                cout << "content: [" << *I << ']' << endl;
            }
        }
        else if (choice == 10){
            cout << characters << endl; 
        }
        else if (choice == 11){
            I = characters.begin();
            for (; I != characters.end(); I++)
                characters.pop_front();
        }
    }
    return 0;
}

