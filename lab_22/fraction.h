#pragma once

#include <iostream>

#include "abstract_decimal.h"

class Fraction : public Decimal{
    int *numer_;
    int *denom_;
public:
    Fraction();
    Fraction(int num, int den);
    Fraction(Fraction& other);
    Fraction(Fraction&& other);
    Fraction& operator=(Fraction& other);
    Fraction& operator=(Fraction&& other);
    ~Fraction();
    friend Fraction operator+(Fraction& a, Fraction& b);
    friend Fraction operator*(Fraction& a, Fraction& b);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
    double convertToDecimal();
};
