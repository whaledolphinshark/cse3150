#include <stdexcept>
#include <iostream>

#include "fraction.h"

Fraction::Fraction(){
    std::cout << "I am in the default constructor\n";
    numer_ = new int(1);
    denom_ = new int(1);
}

Fraction::Fraction(int num, int den){
    std::cout << "I am in the custom constructor\n";
    if (den == 0){
        throw std::runtime_error("Can't divide by zero!");
    }
    numer_ = new int(num);
    denom_ = new int(den);
}

Fraction::Fraction(Fraction& other){
    std::cout << "I am in the copy constructor\n";
    if (other.numer_ == nullptr || other.denom_ == nullptr){
        throw std::runtime_error("Cant't dereference null pointers");
    }
    numer_ = new int(*other.numer_);
    denom_ = new int(*other.denom_);
}

Fraction::Fraction(Fraction&& other){
    std::cout << "I am in the move constructor\n";
    if (other.numer_ == nullptr || other.denom_ == nullptr){
        throw std::runtime_error("Cant't dereference null pointers");
    }
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;
}

Fraction& Fraction::operator=(Fraction& other){
    std::cout << "I am in the assignment operator (lvalue)\n";
    if (other.numer_ == nullptr || other.denom_ == nullptr){
        throw std::runtime_error("Cant't dereference null pointers");
    }
    if (this == &other){
        return *this;
    }
    
    *numer_ = *other.numer_;
    *denom_ = *other.denom_;
    return *this;
}

Fraction& Fraction::operator=(Fraction&& other){
    std::cout << "I am in the assignment operator (rvalue)\n";
    if (other.numer_ == nullptr || other.denom_ == nullptr){
        throw std::runtime_error("Cant't dereference null pointers");
    }
    if (this == &other){
        return *this;
    }

    delete numer_;
    delete denom_;
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;

    return *this;
}

Fraction::~Fraction(){
    std::cout << "I am in the destructor\n";
    delete numer_;
    delete denom_;
}

Fraction operator+(Fraction& a, Fraction& b){
    std::cout << "I am in the plus operator\n";
    if (a.numer_ == nullptr || a.denom_ == nullptr || b.numer_ == nullptr || b.denom_ == nullptr){
        throw std::runtime_error("Can't dereference null pointers");
    }
    return Fraction(*a.numer_ * *b.denom_ + *b.numer_ * *a.denom_, *a.denom_ * *b.denom_);
}

Fraction operator*(Fraction& a, Fraction& b){
    std::cout << "I am in the multiplication operator\n";
    if (a.numer_ == nullptr || a.denom_ == nullptr || b.numer_ == nullptr || b.denom_ == nullptr){
        throw std::runtime_error("Can't dereference null pointers");
    }
    return Fraction(*a.numer_ * *b.numer_, *a.denom_ * *b.denom_);
}

double Fraction::convertToDecimal(){
    std::cout << "I am in the convertToDecimal function\n";
    if (this->numer_ == nullptr || this->denom_ == nullptr){
        throw std::runtime_error("Can't dereference null pointers");
    }
    return (double)*this->numer_ / *this->denom_;
}    

std::ostream& operator<<(std::ostream& os, const Fraction& obj){
    std::cout << "I am in the << operator\n";
    if (obj.numer_ == nullptr || obj.denom_ == nullptr){
        throw std::runtime_error("Can't dereference null pointers");
    }
    os << *obj.numer_ << "/" << *obj.denom_;
    return os;
}
