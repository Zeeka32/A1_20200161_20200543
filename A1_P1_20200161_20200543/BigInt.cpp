#include "BigInt.h"
#include<iostream>
#include<algorithm>


bool BigInt::is_Larger(string x, string y){
    if(x.length() > y.length())
        return true;
    else if(x.length() < y.length())
        return false;
    else
        for(unsigned int i = 0; i < numberSize; i++){
            if(x[i] > y[i])
                return true;
            else if (x[i] < y[i])
                return false;
        }

    return false;
}

bool BigInt::is_equal(string x, string y){
    for(unsigned int  i = 1; i < x.length(); i++){
        if(x[i] != y[i])
            return false;
    }
    return true;
}

string BigInt::Nines_Complement(string str1, string str2){
    string temp; int s1 = str1.length(), s2 = str2.length();
    for(int i = s1 - 1; i > 0; i--){
        temp.push_back(str1[i]);
    }

    for(unsigned int i = 0; i < temp.length(); i++){
        temp[i] = (9 - (temp[i] - '0')) + '0';
    }

    for(int i = 0; i < s2 - s1; i++)
        temp.push_back('9');

    temp.push_back('+');
    reverse(temp.begin(), temp.end());

    return temp;
}

BigInt::BigInt(string decStr){
    bool validDec = true;
    for(unsigned int i = 0; i < decStr.length(); i++)
        if(!isdigit(decStr[i]) && decStr[0] != '-' && decStr[0] != '+'){
            validDec = false;
            break;
        }

    if(validDec && decStr[0] != '-'){

        if(decStr[0] != '+'){
            bigNumber.push_back('+');
        }
        bigNumber += decStr;
        numberSize = bigNumber.size();
    }
    else if(validDec && decStr[0] == '-'){
        bigNumber = decStr;
        numberSize = bigNumber.size();
    }else if(!validDec)
        throw "Error Invalid Input";
}

BigInt::BigInt(int decInt){
    if(decInt < 0){
        bigNumber += std::to_string(decInt);
    }else{
        bigNumber.push_back('+');
        bigNumber += std::to_string(decInt);
    }
    numberSize = bigNumber.size();
}

//we return the size - 1 because the sign is not part of the number's length.
int BigInt::size(){
    return numberSize - 1;
}

BigInt BigInt::operator+(BigInt anotherDec){

    //deterimining which number is larger.
    string answer, bigNum, smallNum;
    bigNum = anotherDec.bigNumber;
    smallNum = this->bigNumber;

    if(this->numberSize > anotherDec.numberSize){
        bigNum = this->bigNumber;
        smallNum = anotherDec.bigNumber;
    }

    //checking if the numbers are equal.
    if(is_equal(bigNum, smallNum) && bigNum[0] != smallNum[0]){
        BigInt zero_case("+0");
        return zero_case;
    }

    //basic math addition.
    int carry = 0, i = bigNum.length() - 1, j = smallNum.length() - 1;
    if((this->bigNumber[0] == anotherDec.bigNumber[0])){

        while(i > 0 && j > 0) {
            int addition = (bigNum[i] - '0') + (smallNum[j] - '0');
            if(addition < 9) {
                if(carry > 0){
                    answer.push_back((addition + 1) + '0');
                    carry--;
                }else
                    answer.push_back(addition + '0');
            }else if (addition == 9){
                if(carry > 0){
                    answer.push_back('0');
                }else answer.push_back('9');
            }else{
                if(carry > 0){
                    answer.push_back((addition %10 + 1) + '0');
                    carry--;
                }else{
                    answer.push_back((addition %10) + '0');
                }
                carry++;
            }
            i--, j--;
        }

        //adding the rest of the larger number.
        while(i > 0){
            int addition = bigNum[i--] - '0';
            if(addition == 9 && carry > 0){
                answer.push_back('0');
            }
            else if(carry > 0 && flag){
                answer.push_back(addition + 1 + '0');
                carry--;
            }
            else if(flag)
                answer.push_back(addition + '0');
        }


        if(carry > 0 && flag)
            answer.push_back('1');

        if((this->bigNumber[0] == '-' && anotherDec.bigNumber[0] == '-'))
            answer.push_back('-');

        reverse(answer.begin(), answer.end());

        string tempStr(answer.begin(), answer.end());
        BigInt temp(tempStr);

        flag = 1;

        return temp;
    }

    //calculating 10's complement.
    smallNum = Nines_Complement(smallNum, bigNum);
    bigNum[0] = '+';

    BigInt temp1(bigNum), temp3("1"), temp2(smallNum);
    temp2 = temp3 + temp2;



    flag = 0;
    BigInt additionAnswer = temp1 + temp2;

    //removing any leading zeros.
    int it = 1;
    while(additionAnswer.bigNumber[it] == '0'){
        additionAnswer.bigNumber.erase(it, 1);
        it++;
    }

    //determing the sign of the answer.
    if(this->numberSize > anotherDec.numberSize)
        additionAnswer.bigNumber[0] = this->bigNumber[0];

    else if(this->numberSize < anotherDec.numberSize)
        additionAnswer.bigNumber[0] = anotherDec.bigNumber[0];

    else if(is_Larger(this->bigNumber, anotherDec.bigNumber))
        additionAnswer.bigNumber[0] = this->bigNumber[0];

    else additionAnswer.bigNumber[0] = anotherDec.bigNumber[0];

    return additionAnswer;
    }

BigInt BigInt::operator- (BigInt anotherDec){

    string bigNum, smallNum;
    bigNum = this->bigNumber;
    smallNum = anotherDec.bigNumber;

    //invert the sign of the number after the - then add them together.
    if(smallNum[0] == '-')
        smallNum[0] = '+';
    else smallNum[0] = '-';

    BigInt temp1(bigNum), temp2(smallNum);

    return temp1 + temp2;

}

BigInt BigInt::operator= (BigInt anotherDec){
    this->bigNumber = anotherDec.bigNumber;
    this->numberSize = anotherDec.numberSize;
    return *this;
}

ostream& operator << (ostream& out, BigInt b){
    if(b.bigNumber[0] == '-')
        out << "-";

    for(int i = 1; i <= b.size(); i++){
            out << b.bigNumber[i];
    }
    return out;
}


int BigInt::flag = 1;
