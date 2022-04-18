#ifndef FRACTION_CALCULATOR_H_INCLUDED
#define FRACTION_CALCULATOR_H_INCLUDED
#include "Fraction.h"
class FractionCalculator {
public:
    void runCalculator (void) {
        cout << "Instructions\n-seperate fractions with spaces\n-write off/OFF to terminate\n-eg. 4/2 + 3/4\n\n";
        Fraction result;string booleanResult, insertedOperator;
        cout << "result: 0" << endl;
        while (true)
        {
            Fraction lhs, rhs;
            bool valid = true;
            while (valid){
                cout << ">>> ";
                try {
                    cin >> lhs >> insertedOperator >> rhs;
                    valid = false;
                }
                catch (string error) {
                    if (error == "OFF" || error == "off"){
                        valid = true;
                        break;
                    }
                    else
                    cout << error << endl;
                    cout << "please retry again" << endl;
                }
            }
            if (valid == true)
                break;
            if (insertedOperator == "+") {
                result = rhs+lhs;
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == "-"){
                result = lhs-rhs;
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == "*"){
                result = rhs * lhs;
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == "/"){
                result = lhs/rhs;
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == ">"){
                booleanResult = (lhs>rhs);
                booleanResult == "1" ? cout << "True\n" : cout << "False\n";
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == "<"){
                booleanResult = (lhs<rhs);
                booleanResult == "1" ? cout << "True\n" : cout << "False\n";
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == ">="){
                booleanResult = (lhs>=rhs);
                booleanResult == "1" ? cout << "True\n" : cout << "False\n";
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == "<="){
                booleanResult = (lhs<=rhs);
                booleanResult == "1" ? cout << "True\n" : cout << "False\n";
                cout << "result: " << result << endl;
            }
            else if (insertedOperator == "=="){
                booleanResult = (rhs==lhs);
                booleanResult == "1" ? cout << "True\n" : cout << "False\n";
                cout << "result: " << result << endl;
            }

        }
    }
};

#endif // FRACTION_CALCULATOR_H_INCLUDED
