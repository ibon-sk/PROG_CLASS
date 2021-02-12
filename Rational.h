/*
 * File: Rational.h
 * Author: Ibón González
 * Date: 10/02/21
 * Coms: Fichero de interfaz de una clase que representa números racionales
 */

#include <iostream>

#pragma once

class Rational {
    private:
        //------------------------------------ Atributos
        int num, den;
        //------------------------------------ Método privado
        void normalize();
    public:
        //------------------------------------ Constructores
        Rational();
        Rational(const Rational& r);
        Rational(const int& n);
        Rational(const int& n, const int& d);
        //------------------------------------ Destructor
        ~Rational();
        //------------------------------------ Operadores miembros
        Rational& operator=(const Rational& r);
        Rational& operator+(const Rational& r);
        Rational& operator-(const Rational& r);
        Rational& operator*(const Rational& r);
        Rational& operator/(const Rational& r);
        //------------------------------------ Operadores no miembros
        friend std::ostream& operator<<(std::ostream& os, const Rational& r);
};
