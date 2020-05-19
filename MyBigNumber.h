
#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber {
private:

public:
   //static MyBigNumber multByOneDigit( const MyBigNumber& num1, int num2);
   static BigNumber multByOneDigit( const BigNumber& num1, int num2);
};


#endif //TA14_MYBIGNUMBER_H
