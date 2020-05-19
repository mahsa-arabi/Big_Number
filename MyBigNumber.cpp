//
// Created by asus on ۱۹/۰۵/۲۰۲۰.
//

#include "MyBigNumber.h"
#include <stdexcept>
using namespace std;
BigNumber MyBigNumber::multByOneDigit(const BigNumber &num1, int num2) {
    if ((num2 /10) != 0){
        throw invalid_argument("this function is for multiply one digit by big number!");
    }
    MyBigNumber multi;
    if( (num1.getNumOfDigits() == 1 && num1[0] == 0) || (num2 == 0) ){
        multi.sign = true;
        multi.numOfDigits = 1;
        multi.numArray=new int8_t[multi.numOfDigits];
        multi[0]=0;
        }else {
        int8_t carry = 0;
        int8_t m = 0;
        multi.sign = true;
        multi.numOfDigits = num1.getNumOfDigits() + 1;
        multi.numArray = new int8_t[multi.numOfDigits];
        size_t i{0};
        for (; i < num1.getNumOfDigits(); ++i) {
            m = (num1[i] * num2) + carry;
            multi[i] = (m % 10);
            carry = m / 10;
        }
        multi[i] = carry;
        if (carry == 0) {
            multi.numOfDigits -= 1;
        }
    }
    return multi;
}
