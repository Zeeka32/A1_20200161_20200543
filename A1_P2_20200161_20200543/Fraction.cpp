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
int Fraction:: GCD (int max, int min) {

    if(max < min)
        std::swap(max, min);

    int remainder = max % min;
    if(remainder == 0)
        return min;

    max = min;
    min = remainder;

    GCD (max, min);
}

void Fraction:: simplify (Fraction& fraction) {

    if (fraction.numerator_ == 0) {
        return;
    }
    else {
        int gcd = GCD(abs(fraction.denomenator_), abs(fraction.numerator_));
        fraction.numerator_ /= gcd;
        fraction.denomenator_ /= gcd;
        if (fraction.denomenator_ < 0 && fraction.numerator_ < 0){
            fraction.denomenator_ = abs (fraction.denomenator_);
            fraction.numerator_ = abs (fraction.numerator_);
        }
        else if (fraction.denomenator_ < 0 && fraction.numerator_ > 0) {
            fraction.denomenator_ *= -1;
            fraction.numerator_ *= -1;
        }
    }
}

bool Fraction:: operator == (const Fraction& rhs) {
    return (rhs.numerator_ == numerator_ && denomenator_ == rhs.denomenator_);
}
bool Fraction:: operator >= (const Fraction& rhs) {
    return (numerator_ >= rhs.numerator_ && denomenator_ >= rhs.denomenator_);
}
bool Fraction:: operator <= (const Fraction& rhs) {
    return (numerator_ <= rhs.numerator_ && denomenator_ <= rhs.denomenator_);
}
bool Fraction:: operator > (const Fraction& rhs) {
    return (numerator_ > rhs.denomenator_ && denomenator_ > rhs.denomenator_);
}
bool Fraction:: operator < (const Fraction& rhs) {
    return (numerator_ < rhs.numerator_ && rhs.denomenator_ < denomenator_);
}


istream& operator >> (istream& in, Fraction& rhs) {

    string input, num, deno;
    in >> input;
    if (input == "OFF" || input == "off")
        throw input;


    for (int i = input.length() - 1;  input[i] != '/' && input.length() > 0; i--){
        deno.push_back(input[i]);
        input.pop_back();
    }


    if(input.length() > 0)
        input.pop_back();

    for (int i = input.length() - 1; input.length() > 0 ; i--){
        num.push_back(input[i]);
        input.pop_back();
    }

    reverse(num.begin(), num.end());
    reverse(deno.begin(), deno.end());

    if (stoi(deno) == 0)
        throw string ("denominator cannot be 0");

    rhs.numerator_ = stoi(num);
    rhs.denomenator_ = stoi(deno);

    rhs.simplify(rhs);


    return in;
}

ostream& operator << (ostream& out, Fraction& rhs) {
    out << rhs.numerator_ << '/' << rhs.denomenator_;
    return out;
}
