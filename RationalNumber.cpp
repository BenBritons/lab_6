//
// Created by Ivan on 20.12.21.
//

#include "RationalNumber.h"
unsigned int gcd(unsigned int num, unsigned int den)
{
    //@link https://cpp.mazurok.com/tag/gcd/

    return (den != 0) ? gcd(den, num%den) : num;
}

void RationalNumber::Reduction() {

    unsigned int g_c_d = 0;
    if(numerator < 0){
        g_c_d = gcd(-numerator, denominator);
    } else{
        g_c_d = gcd(numerator,denominator);
    }
    numerator = numerator / g_c_d;
    denominator = denominator / g_c_d;
}

RationalNumber RationalNumber::Sum(RationalNumber tmp) {
    RationalNumber a(0,1,0);
    if(tmp.integer_part != 0){
        tmp.numerator = tmp.denominator * tmp.integer_part + tmp.numerator;
        tmp.integer_part = 0;
    }
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }
    a.numerator = numerator * tmp.denominator + tmp.numerator * denominator;
    a.denominator = denominator * tmp.denominator;
    if(a.numerator > a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    a.Reduction();
    return a;
}

RationalNumber RationalNumber::Subtraction(RationalNumber tmp) {
    RationalNumber a(0,1,0);
    if(tmp.integer_part != 0){
        tmp.numerator = tmp.denominator * tmp.integer_part + tmp.numerator;
        tmp.integer_part = 0;
    }
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }
    a.numerator = numerator * tmp.denominator - tmp.numerator * denominator;
    a.denominator = denominator * tmp.denominator;
    if(a.numerator >= a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    a.Reduction();
    return a;
}

RationalNumber RationalNumber::Division(RationalNumber tmp) {
    RationalNumber a(0,1,0);
    if(tmp.integer_part != 0){
        tmp.numerator = tmp.denominator * tmp.integer_part + tmp.numerator;
        tmp.integer_part = 0;
    }
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }
    int tmp_int;
    if(tmp.numerator < 0){
        tmp_int = tmp.denominator;
        tmp.denominator = -tmp.numerator;
        tmp.numerator = -tmp_int;

    }else{
        tmp_int = tmp.denominator;
        tmp.denominator = tmp.numerator;
        tmp.numerator = tmp_int;
    }

    a.numerator = tmp.numerator * numerator;
    a.denominator = tmp.denominator * denominator;
    if(a.numerator >= a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    a.Reduction();
    return a;
}

RationalNumber RationalNumber::Multiplication(RationalNumber tmp) {
    RationalNumber a(0,1,0);
    if(tmp.integer_part != 0){
        tmp.numerator = tmp.denominator * tmp.integer_part + tmp.numerator;
        tmp.integer_part = 0;
    }
    if(integer_part != 0){
        numerator = denominator * integer_part + numerator;
        integer_part = 0;
    }

    a.numerator = tmp.numerator * numerator;
    a.denominator = tmp.denominator * denominator;
    if(a.numerator > a.denominator){
        a.integer_part = a.numerator/(a.denominator * 1.0);
        a.numerator = a.numerator - (a.integer_part * a.denominator);
    }
    a.Reduction();
    return a;
}

std::string RationalNumber::ToString() {
    Reduction();
    std::string str;
    str = std::to_string(integer_part) + "X" + "(" + std::to_string(numerator) + "/" + std::to_string(denominator) + ")";
    return str;
}
