#ifndef FRACTION_CALCULATOR_H_INCLUDED
#define FRACTION_CALCULATOR_H_INCLUDED
#include "Fraction.h"

class FractionCalculator {
public:
    void runCalculator (void) {
        cout << "Welcome to Fraction Calculator!" << endl;
        cout << "To use this calculator properly seperate the input by a space" << endl;
        cout << "You can add, subtract, divide and multiply using this calculator, as well as comparing fractions" << endl;
        cout << "Input example: " << endl;
        cout << "               5/2 + 5/2"   << endl;
        cout << "               4/2 > 2/2"   << endl;
        cout << "               5/10 = 5/10" << endl;
        cout << "to exit type off" << endl << endl;
        Fraction result; string insertedOperator; bool booleanResult;
        cout << "result: 0" << endl;
        while (true)
        {
            Fraction lhs, rhs;

            while(true){
                try{
                cout << ">>> ";
                cin >> lhs >> insertedOperator >> rhs;
                }
                catch(string error){
                    if(error == "off" || error == "OFF")
                        return;
                    cout << error << "\n";
                    continue;
                }
                catch(...){
                    cout << "invalid Input\n";
                    continue;
                }
                break;
            }

            if (insertedOperator == "+") {
                result = rhs+lhs;
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == "-"){
                result = lhs-rhs;
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == "*"){
                result = rhs * lhs;
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == "/"){
                result = lhs/rhs;
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == ">"){
                booleanResult = (lhs>rhs);
                booleanResult == true ? cout << "True\n\n" : cout << "False\n\n";
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == "<"){
                booleanResult = (lhs<rhs);
                booleanResult == true ? cout << "True\n\n" : cout << "False\n\n";
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == ">="){
                booleanResult = (lhs>=rhs);
                booleanResult == true ? cout << "True\n\n" : cout << "False\n\n";
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == "<="){
                booleanResult = (lhs<=rhs);
                booleanResult == true ? cout << "True\n\n" : cout << "False\n\n";
                cout << "result: " << result << "\n\n";
            }
            else if (insertedOperator == "="){
                booleanResult = (rhs==lhs);
                booleanResult == true ? cout << "True\n\n" : cout << "False\n\n";
                cout << "result: " << result << "\n\n";
            }
            else{
                cout << "invalid operator\n\n";
            }

        }
    }
};

#endif // FRACTION_CALCULATOR_H_INCLUDED
