
#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber {




    friend BigNumber operator*(const BigNumber & num1, const BigNumber & num2);
  //  friend BigNumber operator* (const BigNumber & num1, const BigNumber & num2);
public:
    static BigNumber multByOneDigit( const BigNumber& num1, int num2);
    MyBigNumber(){}

    MyBigNumber(BigNumber number);
    //BigNumber operator*( const MyBigNumber & num2);
   // BigNumber operator* ( const BigNumber & num2);
    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray ) : BigNumber((std::string) myCharArray) {}
    MyBigNumber(const long & intNum );
    MyBigNumber ( const MyBigNumber & myBig );   // copy constructor

};


#endif //TA14_MYBIGNUMBER_H
