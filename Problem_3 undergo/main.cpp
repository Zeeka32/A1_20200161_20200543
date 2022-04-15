#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;



class MatrixCalculator {
public:
    void Menu () {
        cout<<"1- Perform Matrix Addition\n\n"
            <<"2- Perform Matrix Subtraction\n\n"
            <<"3- Perform Matrix Multiplication\n\n"
            <<"4- Matrix Transpose\n\n"
            <<"5- Exit\n\n";
    }

    void Run () {
        cout << "Welcome to Hussien & Mustafa's Matrix Calculator" << endl;
        cout << "-----------------------------------------------\n\n" << endl;
        Menu();
        while (true) {
            int choice;
            cout << "choice >> "; cin >> choice;
            if(choice == 1){

                unsigned int rows1, columns1, rows2, columns2;
                cout << "Enter the First Matrix's dimensions seperated by a space: ";
                cin >> rows1 >> columns1;

                Matrix <int> matrix1(rows1, columns1);

                cout << "enter the First Matrix: \n";
                cin >> matrix1;

                cout << "Enter the Second Matrix's dimensions seperated by a space: ";
                cin >> rows2 >> columns2;

                Matrix<int> matrix2(rows2, columns2);

                cout << "enter the Second Matrix: \n";
                cin >> matrix2;

                cout << "Results:\n\n" << matrix1 + matrix2 << "\n\n";
            }
            else if(choice == 2){

                unsigned int rows1, columns1, rows2, columns2;
                cout << "Enter the First Matrix's dimensions seperated by a space: ";
                cin >> rows1 >> columns1;

                Matrix<int> matrix1(rows1, columns1);

                cout << "enter the First Matrix: \n";
                cin >> matrix1;

                cout << "Enter the Second Matrix's dimensions seperated by a space: \n";
                cin >> rows2 >> columns2;

                Matrix<int> matrix2(rows2, columns2);

                cout << "enter the Second Matrix: \n";
                cin >> matrix2;

                cout << "Results:\n\n" << matrix1 - matrix2 << "\n\n";
            }
            else if(choice == 3){

                unsigned int rows1, columns1, rows2, columns2;
                cout << "Enter the First Matrix's dimensions seperated by a space: ";
                cin >> rows1 >> columns1;

                Matrix<int> matrix1(rows1, columns1);

                cout << "enter the First Matrix: \n";
                cin >> matrix1;

                cout << "Enter the Second Matrix's dimensions seperated by a space: \n";
                cin >> rows2 >> columns2;

                Matrix<int> matrix2(rows2, columns2);

                cout << "enter the Second Matrix: \n";
                cin >> matrix2;

                cout << "Results:\n\n" << matrix1 * matrix2 << "\n\n";
            }
            else if(choice == 4){

                unsigned int rows1, columns1;
                cout << "Enter the Matrix's dimensions seperated by a space: ";
                cin >> rows1 >> columns1;

                Matrix<int> matrix1(rows1, columns1);

                cout << "enter the Matrix: \n";
                cin >> matrix1;
                cout << "Results:\n\n" << matrix1.transpose() << "\n\n";
            }
            else if(choice == 5){
                cout << "Thanks for using our calculator!";
                break;
            }
            else if(choice < 1 || choice > 5){
                cout << "Invalid choice please choose between 1 and 5\n\n";
            }
            Menu();
        }
    }
};



int main (void) {
    MatrixCalculator myCalculator;
    myCalculator.Run();
    return 0;
}
