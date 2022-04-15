#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class StudentName {
public:
    StudentName (string name) {
        if (name != ""){
            while (name [name.length () - 1] == ' ') {
                name.pop_back ();
            }
            names.push_back ("");
            for (int i = 0, k = 0; i < name.length(); i++){
                if (name[i] != ' '){
                    names[k].push_back (name[i]);
                }
                if (name[i+1] != ' ' && name [i] == ' '){
                    names.push_back ("");
                    k++;
                }
            }
            string last = names[names.size () - 1];
            while (names.size () < 3) {
                names.push_back (last);
            }
        }
        else
            throw string("invalid name!");

    }
    void print (void) {
        for (int i = 0; i < names.size(); i++)
            cout << names [i] << ' ';
        cout << endl;
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

private:
    vector <string> names;
};





int main (void) {
    try {
        cout << "test case 1..."<<endl;
        StudentName name1("Mustafa");
        cout << "name1 is " << "Mustafa" << endl;
        cout << "replace (1,2)" << endl;
        if (name1.replace (1,2)) {cout << "valid replacement!" << endl;name1.print();}
        else {cout << "invalid" << endl;name1.print();}
        cout << endl << "test case 2..."<<endl;

        StudentName name2("Mustafa Muhammad");
        cout << "name2 is " << "Mustafa Muhammad" << endl;
        cout << "replace (1,0)" << endl;
        if (name2.replace (1,0)) {cout << "valid replacement!" << endl;name2.print();}
        else {cout << "invalid" << endl;name2.print();}
        cout << endl << "test case 3..."<<endl;

        StudentName name3("Mustafa Hussien Mukhtar");
        cout << "name3 is " << "Mustafa Hussien" << endl;
        cout << "replace (1,2)" << endl;
        if (name3.replace (1,2)) {cout << "valid replacement!" << endl;name3.print();}
        else {cout << "invalid" << endl;name3.print();}
        cout << endl << "test case 4..."<<endl;

        StudentName name4("Muhammad Muhammad Abd_ElMoaty Mustafa");
        cout << "name4 is " << "Muhammad Muhammad Abd_ElMoaty Mustafa" << endl;
        cout << "replace (1,4)" << endl;
        if (name4.replace (1, 4)) {cout << "valid replacement!" << endl;name4.print();}
        else {cout << "invalid" << endl;name4.print();}
        cout << endl << "test case 5..."<<endl;

        StudentName name5("Mustafa & Hussien");
        cout << "name5 is " << "Mustafa & Hussien" << endl;
        cout << "replace (1,3)" << endl;
        if (name5.replace (1, 3)) {cout << "valid replacement!" << endl;name5.print();}
        else {cout << "invalid" << endl;name5.print();}
    }
    catch (string error) {
        cout << error << endl;
    }
    return 0;
}
