#ifndef FRACTION_CALCULATOR_H_INCLUDED
#define FRACTION_CALCULATOR_H_INCLUDED
#include "Fraction.h"
class FractionCalculator {
public:
    void runCalculator (void) {
        string useResult = "clear";
        Fraction result;bool booleanResult;
        string insertedOperator;
        cout << "operator: "; cin >> insertedOperator;
        while (true)
        {
            Fraction lhs, rhs;
            if (useResult == "1" || useResult == "use") {
                lhs = result;
                cout << "RHS: "; cin >> rhs;
            }
            else {
                cout << "LHS: "; cin >> lhs;
                cout << "RHS: "; cin >> rhs;
            }
            if (insertedOperator == "+") {
                result = rhs+lhs;
                cout << "result is: " << result << endl;
            }
            else if (insertedOperator == "-"){
                result = lhs-rhs;
                cout << "result is: " << result << endl;
            }
            else if (insertedOperator == "*"){
                result = rhs * lhs;
                cout << "result is: " << result << endl;
            }
            else if (insertedOperator == "/"){
                result = lhs/rhs;
                cout << "result is: " << result << endl;
            }
            else if (insertedOperator == ">"){
                booleanResult = (lhs>rhs);
                cout << "result is: " << booleanResult << endl;
            }
            else if (insertedOperator == "<"){
                booleanResult = (lhs<rhs);
                cout << "result is: " << booleanResult << endl;
            }
            else if (insertedOperator == ">="){
                booleanResult = (lhs>=rhs);
                cout << "result is: " << booleanResult << endl;
            }
            else if (insertedOperator == "<="){
                booleanResult = (lhs<=rhs);
                cout << "result is: " << booleanResult << endl;
            }
            else if (insertedOperator == "=="){
                booleanResult = (rhs==lhs);
                cout << "result is: " << booleanResult << endl;
            }
            string resume;
            cout << "1- resume   2- exit\n"; cin >> resume;
            if (resume != "resume" || resume != "1")
                break;
            if (insertedOperator != "<" && insertedOperator != ">" && insertedOperator != "<=" && insertedOperator != "=>" && insertedOperator != "=="){
                cout << "1- use previous result as LHS   2- clear previous result\n";
                cin >> useResult;
            }else{useResult = "clear";}
            cout << "operator: "; cin >> insertedOperator;
        }
    }
};

#endif // FRACTION_CALCULATOR_H_INCLUDED
