#include <iostream>
#include "BigInt.h"
using namespace std;

int main(void) {
    try{
        cout << "Testing initialization with strings\n";
        BigInt x1("12345");
        BigInt y1("11340");

        cout << x1 << " " << y1 << "\n";
        cout << "\nTest OK\n\n";

        cout << "testing initialization with integers\n";

        BigInt x2(5000);
        BigInt y2(-49980);

        cout << x2 << " " << y2 << "\n";
        cout << "\nTest OK\n\n";

        cout << "testing addition/substraction operators\n";

        cout << x1 << " + " << y1 << " = " << x1 + y1 << "\n";
        cout << x1 << " + " << y2 << " = " << x1 + y2 << "\n";
        cout << x1 << " - " << y2 << " = " << x1 - y2 << "\n";
        cout << x2 << " - " << y2 << " = " << x2 - y2 << "\n";
        cout << y2 << " - " << x1 << " = " << y2 - x1 << "\n";

        cout << "\nTest OK\n\n";

        cout << "testing assignment operator\n";

        BigInt x3("0");
        x3 = x1 + x2;

        cout << "x3 = " << x1 << " + " << x2 << "\n";
        cout << "x3 = " << x3 << "\n";

        cout << "\nTest OK\n\n";

        cout << "testing size function\n";

        cout << x1 << " length is: " << x1.size() << "\n";
        cout << x2 << " length is: " << x2.size() << "\n";
        cout << y1 << " length is: " << y1.size() << "\n";
        cout << y2 << " length is: " << y2.size() << "\n";

        cout << "\nTest OK\n\n";
    }catch(char const* e){
        cout << e;
    }
    return 0;

}

