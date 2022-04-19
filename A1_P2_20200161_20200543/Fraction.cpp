#include "Fraction.h"

Fraction Fraction:: operator + (const Fraction& rhs) {
    Fraction result;
    result.numerator_ = numerator_*rhs.denomenator_ + rhs.numerator_* denomenator_;
    result.denomenator_ = denomenator_ * rhs.denomenator_;
    simplify(result);
    return result;
}
Fraction Fraction:: operator - (const Fraction& rhs) {
    Fraction result;
    result.numerator_ = numerator_*rhs.denomenator_ - rhs.numerator_* denomenator_;
    result.denomenator_ = denomenator_ * rhs.denomenator_;
    simplify(result);
    return result;
}
Fraction Fraction:: operator * (const Fraction& rhs) {
    Fraction result;
    result.numerator_ = numerator_ * rhs.numerator_;
    result.denomenator_ = denomenator_ * rhs.denomenator_;
    simplify(result);
    return result;
}
Fraction Fraction:: operator / (const Fraction& rhs) {
    Fraction result;
    result.numerator_ = numerator_ * rhs.denomenator_;
    result.denomenator_ = denomenator_ * rhs.numerator_;
    simplify(result);
    return result;
}
int Fraction:: GCD (int min,const Fraction& fraction) {
    if ((fraction.denomenator_% min == 0) && (fraction.numerator_% min == 0) || min <= 1)
        return min;
    GCD (--min, fraction);
}
void Fraction:: simplify (Fraction& fraction) {
    if (fraction.numerator_ == 0) {
        return;
    }
    else {
        int gcd = GCD (std::min(abs(fraction.numerator_), abs(fraction.denomenator_)), fraction);
        fraction.numerator_ /= gcd;
        fraction.denomenator_ /= gcd;
        if (fraction.denomenator_ < 0 && fraction.numerator_ < 0){
            fraction.denomenator_ = abs (fraction.denomenator_);
            fraction.numerator_ = abs (fraction.numerator_);
        }
    }
}

bool Fraction:: operator == (const Fraction& rhs) {
    return (rhs.numerator_/rhs.denomenator_ == numerator_/denomenator_);
}
bool Fraction:: operator >= (const Fraction& rhs) {
    return (numerator_/denomenator_ >= rhs.numerator_/rhs.denomenator_);
}
bool Fraction:: operator <= (const Fraction& rhs) {
    return (numerator_/denomenator_ <= rhs.numerator_/rhs.denomenator_);
}
bool Fraction:: operator > (const Fraction& rhs) {
    return (numerator_/denomenator_ > rhs.numerator_/rhs.denomenator_);
}
bool Fraction:: operator < (const Fraction& rhs) {
    return (numerator_/denomenator_ < rhs.numerator_/rhs.denomenator_);
}


istream& operator >> (istream& in, Fraction& rhs) {
    string input, num, deno;bool right = true;int slash = 0, negative = 0;
    in >> input;
    if (input.length() < 3 || input[0] == '/' || input [input.length()-1] == '/')
        throw string ("Invalid Input cause: Entered value is not a proper fraction, expected x/y");
    if (input == "OFF" || input == "off")
        throw input;
    for (int i = 0; i < input.length (); i++){
        if (input [i] == '-')
            negative++;
        if (input [i] == '/')
            slash++;
        if (!isdigit(input[i]) && input[i] != '/' && input[i] != '-')
            throw string ("not number");
    }
    if (slash != 1 || negative > 2)
        throw string ("multiple operators");
    for (int i = input.length() - 1;  input[i] != '/' ; i--){
        if (input [i] == '-' && input [i-1] != '/')
            throw string ("minus position error");
        deno.push_back(input[i]);
        input.pop_back();
    }
    input.pop_back();
    for (int i = input.length() - 1; input.length() > 0 ; i--){
        if (input [i] == '-' && i != 0)
            throw string ("minus position error");
        num.push_back(input[i]);
        input.pop_back();
    }
    reverse(num.begin(), num.end());
    reverse(deno.begin(), deno.end());
    if (stoi(deno) == 0)
        throw string ("denominator cannot be 0");

    std::stringstream ss;
    ss << num;
    ss >> rhs.numerator_;

    ss << deno;
    ss >> rhs.denomenator_;

    rhs.simplify(rhs);
    return in;
}

ostream& operator << (ostream& out, Fraction& rhs) {
    out << rhs.numerator_ << '/' << rhs.denomenator_;
    return out;
}
