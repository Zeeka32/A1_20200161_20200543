#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class StudentName {
private:
    vector <string> names;
public:
    StudentName (string name) {
        if (name != ""){//checking if empty string 
            while (name [name.length () - 1] == ' ') {//popping end spaces if exist
                name.pop_back ();
            }
            names.push_back ("");//first entry
            for (int i = 0, k = 0; i < name.length(); i++){
                if (name[i] != ' '){//if found non space fill name
                    names[k].push_back (name[i]);
                }
                if (name[i+1] != ' ' && name [i] == ' '){// found space make new entry
                    names.push_back ("");
                    k++;
                }
            }
            string last = names[names.size () - 1];
            while (names.size () < 3) {//duplicating last name
                names.push_back (last);
            }
        }
        else
            throw string("cannot have an empty string as an name");

    }
    void print (void) {
        for (int i = 0; i < names.size(); i++)
            cout << i+1 << ')' << names [i] << "\n";
    }
    bool replace (int i, int j) {
        i--; j--;
        if ( (i < names.size ()) && (j < names.size ()) && (i >= 0) && (j >= 0) ){
            std::swap (names [i], names [j]);
            return true;
        }
        else
            return false;
    }

};


int main (void) {
    try {

        cout << "test case 1...\n";
        StudentName name1("Mustafa");
        cout << "before replacement: \n";
        name1.print();
        if (name1.replace (1,2)){
            cout << "\nafter replace (1, 2): \n";
            name1.print();
        }
        else cout << "invalid\n";


        cout << "\ntest case 2...\n";
        StudentName name2("Ahmad Muhammad");
        cout << "before replacement: \n";
        name2.print();
        if (name2.replace (1,0)){
            cout << "\nafter replace (1, 0): \n";
            name2.print();
        }
        else cout << "after replace (1, 0): invalid\n";



        cout <<"\ntest case 3...\n";
        StudentName name3("Mustafa Hussien Mukhtar");
        cout << "before replacement: \n";
        name3.print();
        if (name3.replace (1,2)){
            cout << "\nafter replace (1, 2): \n";
            name3.print();
        }
        else cout << "invalid\n";


        cout <<"\ntest case 4...\n";
        StudentName name4("Iman Muhammad Abd_ElMoaty Hassan");
        cout << "before replacement: \n";
        name4.print();
        if (name4.replace (1, 4)){
            cout << "\nafter replace (1, 4): \n";
            name4.print();
        }
        else cout << "invalid\n";


        cout << "\ntest case 5...\n";
        StudentName name5("Ramadan Mahmoud");
        cout << "before replacement: \n";
        name5.print();
        if (name5.replace (1, 3)){
            cout << "\nafter replace (1, 3): \n";
            name5.print();
        }
        else cout << "invalid\n";

    }
    catch (string error) {
        cout << error << endl;
    }
    return 0;
}
