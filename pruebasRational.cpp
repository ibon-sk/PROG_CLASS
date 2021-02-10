/*
 * File: mainRational.cpp
 * Author: Ibón González
 * Date: 10/02/21
 * Coms: Fichero de pruebas que implementa una calculadora de racionales
 *       (utilizando la clase Rational)
 */

#include "Rational.h"

using namespace std;

int main() {
    int operation;
    cout << "----------------------------------" << endl;
    cout << "RATIONAL NUMBERS CALCULATOR:\nOperations:\n\t0. End program\n\t1. Addition\n\t2. Substraction\n\t3. Multiplication\n\t4. Division\n\t5. Show menu" << endl;
    do {
        cout << "----------------------------------" << endl;
        cout << "Choose an operation (0-5): " << flush;
        cin >> operation;
        if(operation == 0) {
            cout << "Bye!" << endl;
        }
        else if (operation == 5) {
            cout << "----------------------------------" << endl;
            cout << "RATIONAL NUMBERS CALCULATOR:\nOperations:\n\t0. End program\n\t1. Addition\n\t2. Substraction\n\t3. Multiplication\n\t4. Division\n\t5. Show menu" << endl;
        }
        else if (operation > 5) {
            cerr << "Choose a correct operation!" << endl;
        }
        else{
            cout << "Choose two rationals (n1 d1 n2 d2): " << flush;
            int n1, d1, n2, d2;
            cin >> n1 >> d1 >> n2 >> d2;
            Rational r1(n1, d1);
            Rational r2(n2, d2);
            cout << "----------------------------------" << endl;
            if (operation == 1) {
                cout << "Addition:" << endl;
                cout << r1 << " + " << r2 << " = " << r1+r2 << endl;
            }
            else if (operation == 2) {
                cout << "Substraction:" << endl;
                cout << r1 << " - " << r2 << " = " << r1-r2 << endl;
            }
            else if (operation == 3) {
                cout << "Multiplication:" << endl;
                cout << r1 << " * " << r2 << " = " << r1*r2 << endl;
            }
            else {
                cout << "Division:" << endl;
                cout << r1 << " ÷ " << r2 << " = " << r1/r2 << endl;
            }
        }
    } while (operation != 0);
    return 0;
}