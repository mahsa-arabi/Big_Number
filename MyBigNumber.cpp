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

MyBigNumber::MyBigNumber(BigNumber number) {
     numOfDigits=number.getNumOfDigits();
     sign=number.getSign();
     numArray=new int8_t[numOfDigits];
    for(size_t i{0}; i < numOfDigits; ++i){
        numArray[i] = number[i];
    }
}


MyBigNumber::MyBigNumber( const std::string & str){
    setValues( str );
}

MyBigNumber:: MyBigNumber(const long & intNum ){
    sign = ( intNum >= 0 );

    long temp1 = abs(intNum);
    numOfDigits = 0;
    while ( temp1 > 0 ){
        ++numOfDigits;
        temp1 /= 10;
    }

    numArray = new int8_t[numOfDigits];
    long temp2 = abs(intNum);
    for( size_t i{0}; i < numOfDigits; ++i ){
        numArray[i] = temp2 % 10;
        temp2 /= 10;
    }
}

MyBigNumber:: MyBigNumber ( const  MyBigNumber & myBig ){
    sign = myBig.sign;
    numOfDigits = myBig.numOfDigits;
    numArray = new int8_t[numOfDigits];
    for(size_t i{0}; i < numOfDigits; ++i){
        numArray[i] = myBig[i];
    }
}

BigNumber operator*(const BigNumber &num1, const BigNumber &num2) {
    BigNumber multi="0";
    BigNumber bMax = BigNumber::unsignedMax(num1, num2);
    BigNumber bMin = BigNumber::unsignedMin(num1, num2);
    BigNumber multiTemp;
    for (size_t i {0}; i <bMin.getNumOfDigits() ; ++i) {
        multiTemp = (MyBigNumber::multByOneDigit(bMax,bMin[i])<<i);
        multi = multi + multiTemp;
    }
    if(num1.getSign() == num2.getSign()){
        multi.sign=true;
    }else{
        multi.sign=false;
    }
    return multi;
}


