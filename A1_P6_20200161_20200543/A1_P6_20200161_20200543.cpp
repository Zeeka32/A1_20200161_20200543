#include <iostream>
using namespace std;

class PhoneDirectory {
private:
    string *phoneNumber;
    string *firstName;
    string *lastName;
    int length = 0;
    int MaxLength = 1;

    void Allocate(int size){
        string *phoneTemp = phoneNumber;
        string *firstNameTemp = firstName;
        string *lastNameTemp = lastName;

        phoneNumber  = new string[size];
        firstName    = new string[size];
        lastName     = new string[size];

        for(int i = 0; i < length; i++){
            phoneNumber[i] = phoneTemp[i];
            firstName[i] = firstNameTemp[i];
            lastName[i] = lastNameTemp[i];
        }

        MaxLength *= 2;

        delete [] phoneTemp;
        delete [] firstNameTemp;
        delete [] lastNameTemp;

    }

    void insertionSort(string str[], int size){
        for(int i = 1, j = 0; i < size; i++){
            string tempElement1 = str[i];
            string tempElement2 = lastName[i];
            string tempElement3 = phoneNumber[i];

            for(j = i; j > 0 && tempElement1 < str[j - 1]; j--){
                str[j] = str[j - 1];
                lastName[j] = lastName[j - 1];
                phoneNumber[j] = phoneNumber[j - 1];
            }
            str[j]         = tempElement1;
            lastName[j]    = tempElement2;
            phoneNumber[j] = tempElement3;
        }
    }

public:

    PhoneDirectory(){
        phoneNumber = new string[MaxLength];
        firstName = new string[MaxLength];
        lastName = new string[MaxLength];
    }


    void Add_Entry(string phone, string f_name, string l_name){
        if(length >= MaxLength){
            PhoneDirectory::Allocate(MaxLength * 2);
            phoneNumber[length] = phone;
            firstName[length] = f_name;
            lastName[length] = l_name;
            length++;
        }else{
            phoneNumber[length] = phone;
            firstName[length] = f_name;
            lastName[length] = l_name;
            length++;
        }
    }

    bool Delete_Entry(string f_name){
        
        if(length == 0)
            return false;

        if(length == 1){
            length = 0;
        }

        PhoneDirectory::insertionSort(firstName, length);

        int L = 0, R = length - 1;
        while(L <= R){
            int mid = L + (R - L) / 2;
            if(firstName[mid] == f_name){
                for(int i = mid + 1; i < length; i++){
                    swap(firstName[i], firstName[i - 1]);
                    swap(lastName[i], lastName[i - 1]);
                    swap(phoneNumber[i], phoneNumber[i - 1]);
                }
                length--; return true;
            }
            if(firstName[mid] > f_name)
                R = mid - 1;
            else
                L = mid + 1;
        }

        return false;
    }

    string Lookup_Phone(string phone){
        for(int i = 0; i < length; i++){
            if(phone == phoneNumber[i]){
                string fullname = firstName[i] + " " + lastName[i];
                return fullname;
            }
        }
        return "Not Found";
    }

    string Lookup_Fname(string f_name){

        PhoneDirectory::insertionSort(firstName, length);

        int L = 0, R = length - 1;
        while(L <= R){
            int mid = L + (R - L) / 2;
            if(firstName[mid] == f_name){
                string details = firstName[mid] + " " + lastName[mid] + " Phone: " + phoneNumber[mid];
                return details;
            }
            if(firstName[mid] > f_name)
                R = mid - 1;
            else
                L = mid + 1;
        }

        return "Not Found";
    }

    void List_Directory(){

        PhoneDirectory::insertionSort(firstName, length);
        
        cout << "First Name\tLast Name\tPhone\n";

        for(int i=0; i < length; i++){
            cout << firstName[i] << "\t\t" << lastName[i] << "\t\t" << phoneNumber[i] << "\n";
        }
    }

    ~PhoneDirectory(){
        delete phoneNumber;
        delete firstName;
        delete lastName;
    }

};

int main()
{   

    PhoneDirectory entries;
    int choice = 0;
    while(choice != 6){

        cout<< "1. Add an entry to the directory\n"
            << "2. Look up a phone number\n"
            << "3. Look up by first name\n"
            << "4. Delete an entry from the directory\n"
            << "5. List All entries in phone directory\n"
            << "6. Exit from this program\n"
            << "Choice >> ";
        cin >> choice;
        if(choice == 1){

            string firstName, lastName, phone;
            cout << "Enter the First name, last name, and phone number: ";
            cin >> firstName >> lastName >> phone;
            entries.Add_Entry(phone, firstName, lastName);

        }else if(choice == 2){
            
            string phone;
            cout << "Enter the Phone number you wish to look up: ";
            cin >> phone;
            string lookup = entries.Lookup_Phone(phone);
            if(lookup != "Not Found")
                cout << "\n\nthis phone number belongs to " << lookup << "\n\n";
            else
                cout << "\n\nphone number not found\n\n";

        }else if(choice == 3){

            string firstName;
            cout << "Enter the first name you wish to look up: ";
            cin >> firstName;

            string lookup = entries.Lookup_Fname(firstName);

            if(lookup != "Not Found")
                cout << "\n\nDetails about this user: " << lookup << "\n\n";
            else
                cout << "\n\nphone number not found\n\n";

        }else if(choice == 4){

            string firstName;
            cout << "Enter the first name of the person you wish to delete: ";
            cin >> firstName;

            if(entries.Delete_Entry(firstName))
                cout << "user deleted successfully\n\n";
            else
                cout << "no such user exists\n\n";
        }else if(choice == 5){
            entries.List_Directory();
        }else if(choice < 1 || choice > 6){
            cout << "invalid choice please choose between 1 to 6";
        }
    }
    return 0;
}