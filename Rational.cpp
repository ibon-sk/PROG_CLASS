/*
 * File: Rational.cpp
 * Author: Ibón González
 * Date: 10/02/21
 * Coms: Fichero de implementación de una clase que representa números racionales
 */

#include "Rational.h"

//-------------------------------------------- Constructores de la clase Rational
Rational::Rational() : num(1), den(1) { }
Rational::Rational(const int& n, const int& d) : num(n), den(d) { }
Rational::Rational(const Rational& r) {
    *this = r;
}
//-------------------------------------------- Destructor de la clase Rational (no hace nada)
Rational::~Rational() { }
//-------------------------------------------- Funciones auxiliares
// Cálculo del máximo común divisor de dos enteros
int mcd(int a, int b) {
    int mcd = 0;
    int n1 = max(a,b);
    int n2 = min(a,b);
    do {
        mcd = b;
        b = a%b;
        a = mcd;
    } while (b != 0);
    return mcd;
}
// Cálculo del mínimo común múltiplo de dos enteros
int mcm(int a, int b) {
    int mcm = 0;
    int n1 = max(a,b);
    int n2 = min(a,b);
    mcm = a/mcd(a,b)*b;
    return mcm;
}
//-------------------------------------------- Método privado de la clase Rational
void Rational::normalize() {
    int m;
    m = mcd(abs(num), abs(den));
    num = num / m;
    den = den / m;
}
//-------------------------------------------- Sobrecarga de operadores
// Sobrecarga del operador '<<'
ostream& operator<<(ostream& os, const Rational& r) {
    os << r.num << '/' << r.den;
    return os;
}

// Sobrecarga del operador '='
Rational& Rational::operator=(const Rational& r) {
    this->num = r.num;
    this->den = r.den;
    return *this;
}
// Sobrecarga del operador '+'
Rational& Rational::operator+(const Rational& r) {
    int d = mcm(this->den, r.den);
    int n = d/this->den * this->num + d/r.den*r.num;
    this->den = d;
    this->num = n;
    this->normalize();
    return *this;
}
// Sobrecarga del operador '-'
Rational& Rational::operator-(const Rational& r) {
    int d = mcm(this->den, r.den);
    int n = d/this->den * this->num - d/r.den*r.num;
    this->den = d;
    this->num = n;
    normalize();
    return *this;
}
// Sobrecarga del operador '*'
Rational& Rational::operator*(const Rational& r) {
    this->den = this->den * r.den;
    this->num = this->num * r.num;
    normalize();
    return *this;
}
// Sobrecarga del operador '/'
Rational& Rational::operator/(const Rational& r) {
    int d = this->den * r.num;
    int n = this->num * r.den;
    this->den = d;
    this->num = n;
    normalize();
    return *this;
}