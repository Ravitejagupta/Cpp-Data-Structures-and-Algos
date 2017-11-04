/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calculator.h
 * Author: neven1
 *
 * Created on October 31, 2017, 1:27 AM
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>

using namespace std;

class Calculator {
public:
    Calculator(string expression);
    
        
    double calculateExpression(string expression);
    double calculateTerm(string expression);
    double calculateFactor(string expression);
    
    void initializeMethod(string expression);
    void reset();
    
private:
    static int openBracket;
    static int closeBracket;

};

#endif /* CALCULATOR_H */

