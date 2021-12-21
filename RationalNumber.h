//
// Created by Ivan on 20.12.21.
//

#ifndef LAB_6_RATIONALNUMBER_H
#define LAB_6_RATIONALNUMBER_H
#include <string>

unsigned int gcd(unsigned int num, unsigned int den);

class RationalNumber {
private:
    int integer_part;
    int numerator;
    unsigned int denominator;
    void Reduction();
public:
    RationalNumber() = default;
    RationalNumber(int num, unsigned int den, int i_p):numerator(num), denominator(den), integer_part(i_p){}
    RationalNumber Sum(RationalNumber tmp);
    RationalNumber Subtraction(RationalNumber tmp);
    RationalNumber Division(RationalNumber tmp);
    RationalNumber Multiplication(RationalNumber tmp);
    std::string ToString();
    int GetInteger(){
        return integer_part;
    };
    int GetNumenator(){
        return numerator;
    }
    unsigned int GetDenominator(){
        return denominator;
    }

};


#endif //LAB_6_RATIONALNUMBER_H
