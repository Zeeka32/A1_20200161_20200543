#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;



class Fraction {
private:
    int numerator_;
    int denomenator_;
public:
    Fraction operator + (const Fraction&);
    Fraction operator - (const Fraction&);
    Fraction operator * (const Fraction&);
    Fraction operator / (const Fraction&);
    int GCD (int, const Fraction&);
    void simplify (Fraction&);
    bool operator == (const Fraction& rhs);
    bool operator >= (const Fraction& rhs);
    bool operator <= (const Fraction& rhs);
    bool operator > (const Fraction& rhs);
    bool operator < (const Fraction& rhs);
    friend istream& operator >> (istream&, Fraction&);
    friend ostream& operator << (ostream&, Fraction&);
};

#endif // FRACTION_H_INCLUDED
