#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"
using namespace std;

int main() {
    cout << boolalpha;
    BigNumber x{-37};
    string str = "-0000";
    BigNumber y{str};
    cout << y << endl;
   // cout << "Enter a number: ";
   //cin >> x;
    x = -y;
    BigNumber z = -y;
    cout << (x != y) << endl;
  BigNumber myBig1 = "-17319";
  BigNumber myBig2 = "000870";
 // cout << BigNumber::unsignedLessOrEqual(myBig1, myBig2) << endl;
  //BigNumber a = BigNumber::unsignedSubtract(myBig1, myBig2);
    cout << (myBig2>>1) << "\t" << (myBig1>>3).getSign() << endl;
//    try{
//        cout << BigNumber::unsignedSubtract(myBig1, myBig2) << endl;
//    }
//    catch( out_of_range e){
//        cout << e.what() << endl;
//    }
    return 0;
}
