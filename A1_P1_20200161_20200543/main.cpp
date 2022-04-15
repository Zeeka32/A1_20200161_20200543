#include <iostream>
#include "BigInt.h"
using namespace std;


int main(void) {
    try{
        //Test case1
        BigInt x1("123456789012345678901234567890");
        BigInt y1("113456789011345678901134567890");

        BigInt num1 = x1 + y1;

        cout << "123456789012345678901234567890 + 113456789011345678901134567890 = ";
        cout << num1 << "\n\n";

        //Test case2
        BigInt x2("123456789012345678901234567890");
        BigInt y2("1134567890");

        cout << "123456789012345678901234567890 + 11345678901134567890113456789 = ";
        cout << x2 + y2 << "\n\n";

        //Test case3
        BigInt x3("99999999999999");
        BigInt y3("999999999999999");

        cout << "99999999999999 + 99999999999999 = ";
        cout << x3 + y3 << "\n\n";

        //Test case4
        BigInt x4("-99999999999999");
        BigInt y4("-99999999999999");

        BigInt num2 = x4 + y4;
        cout << "-99999999999999 + -99999999999999 = ";
        cout << num2 << "\n\n";

        //Test case5
        BigInt x5(-999999);
        BigInt y5(413456);

        cout << "413456 - 999999 = ";
        cout << x5 + y5 << "\n\n";

    }catch(char const* e){
        cout << e;
    }
    return 0;

}
