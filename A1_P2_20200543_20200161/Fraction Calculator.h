#ifndef FRACTION_CALCULATOR_H_INCLUDED
#define FRACTION_CALCULATOR_H_INCLUDED
#include "Fraction.h"
class FractionCalculator {
public:
    FractionCalculator () {}
    void printCalculator (void) const {
        cout << "input example: 3/1 + 2/5"<< endl;
        cout << "-------------------------" << endl;
        cout << "|                       |" << endl;
        cout << "-------------------------" << endl;
        cout << "|  7  |  8  |  9  |  *  |" << endl;
        cout << "|  4  |  5  |  6  |  /  |" << endl;
        cout << "|  1  |  2  |  3  |  +  |" << endl;
        cout << "| ==  |  0  |  9  |  -  |" << endl;
        cout << "| >=  |  >  |  <  |  <= |" << endl;
        cout << "-------------------------" << endl;
        cout << "|          OFF          |" << endl;
        cout << "-------------------------" << endl;
    }
    void printCalculator (Fraction& result)  {
        cout << "-------------------------" << endl;
        cout << "|                    "<< result <<"|" << endl;
        cout << "-------------------------" << endl;
        cout << "|  7  |  8  |  9  |  *  |" << endl;
        cout << "|  4  |  5  |  6  |  /  |" << endl;
        cout << "|  1  |  2  |  3  |  +  |" << endl;
        cout << "| ==  |  0  |  9  |  -  |" << endl;
        cout << "| >=  |  >  |  <  |  <= |" << endl;
        cout << "-------------------------" << endl;
        cout << "|          OFF          |" << endl;
        cout << "-------------------------" << endl;
    }
    void printCalculator (bool boolean) const {
        cout << "-------------------------" << endl;
        cout << "|                  ";
        (boolean == 1? cout << "True": cout << "False" <<"|");
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "|  7  |  8  |  9  |  *  |" << endl;
        cout << "|  4  |  5  |  6  |  /  |" << endl;
        cout << "|  1  |  2  |  3  |  +  |" << endl;
        cout << "| ==  |  0  |  9  |  -  |" << endl;
        cout << "| >=  |  >  |  <  |  <= |" << endl;
        cout << "-------------------------" << endl;
        cout << "|          OFF          |" << endl;
        cout << "-------------------------" << endl;
    }
    void runCalculator (void) {
        printCalculator ();
        while (true)
        {
            Fraction lhs, rhs, result;
            bool boolean;
            std::string insertedOperator;
            cout << "insert >> "; cin >> lhs >> insertedOperator >> rhs;
            if (insertedOperator == "+") {
                result = rhs+lhs;
                printCalculator(result);
            }
            else if (insertedOperator == "-"){
                result = lhs-rhs;
                printCalculator(result);
            }
            else if (insertedOperator == "*"){
                result = rhs * lhs;
                printCalculator(result);
            }
            else if (insertedOperator == "/"){
                result = lhs/rhs;
                printCalculator(result);
            }
            else if (insertedOperator == ">"){
                boolean = (lhs>rhs);
                printCalculator(boolean);
            }
            else if (insertedOperator == "<"){
                boolean = (lhs<rhs);
                printCalculator(boolean);
            }
            else if (insertedOperator == ">="){
                boolean = (lhs>=rhs);
                printCalculator(boolean);
            }
            else if (insertedOperator == "<="){
                boolean = (lhs<=rhs);
                printCalculator(boolean);
            }
            else if (insertedOperator == "=="){
                boolean = (rhs==lhs);
                printCalculator(boolean);
            }
            else if (insertedOperator == "OFF"){
                break;
            }
        }
    }
};

#endif // FRACTION_CALCULATOR_H_INCLUDED
