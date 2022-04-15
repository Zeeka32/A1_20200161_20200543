#ifndef BIGINT_H
#define BIGINT_H

#include<iostream>

using std::ostream;
using std::string;

class BigInt {
private:
    string bigNumber;
    unsigned int numberSize;
    static int flag;

    bool is_equal(string x, string y);
    bool is_Larger(string x, string y);
    string Nines_Complement(string str1, string str2);

public:

    BigInt(string decStr);
    BigInt(int decInt);

    int size();

    BigInt operator+(BigInt anotherDec);
    BigInt operator- (BigInt anotherDec);
    BigInt operator= (BigInt anotherDec);

    friend ostream& operator << (ostream& out, BigInt b);
};


#endif // BIGINT_H
