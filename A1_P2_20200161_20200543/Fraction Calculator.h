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
        cout << "               5/2 + 5/2 = 5/1" << endl;
        cout << "               4/2 > 2/2 = True" << endl;
        cout << "to exit type off" << endl << endl;
        Fraction result; string insertedOperator; bool booleanResult;
        cout << "result: 0" << endl;
        while (true)
        {
            Fraction lhs, rhs;
            bool valid = true;
            while (valid){
                cout << ">>> ";
                try {
                    cin >> lhs;
                    valid = false;
                }
                catch (string error) {
                    if (error == "OFF" || error == "off"){
                        valid = true;
                        break;
                    }
                    else
                    cout << error << "\n\n";
                }
            }
            if (valid == true)
                break;
            cin >> insertedOperator;
            valid = true;
            while (valid){
                try {
                    cin >> rhs;
                    valid = false;
                }
                catch (string error) {
                    if (error == "OFF" || error == "off"){
                        valid = true;
                        break;
                    }
                    else
                    cout << error << "\n\n";
                    cout << ">>> ";
                }
            }
            if (valid == true)
                break;
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

        }
    }
};

#endif // FRACTION_CALCULATOR_H_INCLUDED
