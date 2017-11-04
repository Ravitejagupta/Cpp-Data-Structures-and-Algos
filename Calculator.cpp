/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calculator.cpp
 * Author: neven1
 * 
 * Created on October 31, 2017, 1:27 AM
 */

#include <iostream>
#include <string.h>
#include "Calculator.h"

using namespace std;

int Calculator::closeBracket = 0;
int Calculator::openBracket = 0;

Calculator::Calculator(string expression) {

    //cout << "Inside Constructor" << endl;
    //cout << expression << endl;
    initializeMethod(expression);

}

void Calculator::reset() {
    closeBracket = 0;
    openBracket = 0;
}

void Calculator::initializeMethod(string expression) {

    string val, temp = expression;
    int base, value = 1;

    // Logic to split e and E and add it back to expression begins
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == 'e' || expression[i] == 'E') {
            if (expression[i] == 'e')
                expression[i] = '/';
            else
                expression[i] = '*';

            val = expression[i + 2];
            base = atof(val.c_str());

            for (int k = 0; k < base; k++)
                value *= 10;

            val = to_string(value);
          //  cout << val << endl;
            expression.insert(i + 1, val);
        }
    }

    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == 'e' || temp[i] == 'E') {
            val = temp.substr(i + 3, temp.length());
            expression.insert(i + base + 2, val);
            expression[i + base + 2 + val.length()] = '\0';
        }
    }

    temp = "";

    for (int i = 0; expression[i] != '\0'; i++)
        temp += expression[i];

    expression = temp;
    // Logic to split e and E and add it back to expression ends

    // Logic to check equivalence of brackets begins
    try{
       // cout << "inside try" << endl;
        
        for (int i = 0; expression[i] != '\0'; i++)
        {
            if(expression[i] == '(')
                openBracket++;
            else if(expression[i] == ')')
                closeBracket++;
        }
        
        if (openBracket != closeBracket)
        {
            //cout << "inside if" << endl;
            int i = 0;
            throw i;
        }
    }
    catch(int i)
    {
       // cout << "inside catch" << endl;
        if(openBracket > closeBracket)
            cout << "***** Unexpected (" << endl;
        else
            cout << "***** Unexpected )" << endl;
        return;
    }
    // Logic to check equivalence of brackets ends
    
    // Logic to check special characters begins
    try
    {
        for (int i = 0; expression[i] != '\0'; i++)
        {
            // Ascii values used to check if the character is a special character.
            // Ascii values 48 to 57 correspond to 0 to 9.
            
            if(int(expression[i]) != 40 && int(expression[i]) != 41 && int(expression[i]) != 42 && int(expression[i]) != 43
                && int(expression[i]) != 45 && int(expression[i]) != 46 && int(expression[i]) != 47 )
            {
                if((int(expression[i]) >= 48 && int(expression[i] <= 57)))
                    continue;
                else 
                {
                    string str = "***** Unexpected ";
                    str += expression[i];                    
                    throw str;
                }
            }
        }
    }
    catch(string str)
    {
        cout << str << endl;
        return;
    }
    // Logic to check special characters ends
    
    //cout << expression << endl;
    double temp1 = calculateExpression(expression);
    cout << temp1 << endl;
}

double Calculator::calculateExpression(string expression) {
    // Split the string when there is + or - sign.

    cout << "Inside calculate Expression" << endl;
    cout << expression << endl;


    string first_expression = "", rest_expression;
    char op = '\0';
    char op1 = '\0';
    char op2 = '\0';
    int k = 0;
    // double  nee = 0;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(') {
            //below if  change, add + and -
            if ((expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-') && expression[i+1] != '(') {
                
                for (k = i; expression[k] != '\0'; k++) {
                    if (expression[k] == '+' || expression[k] == '-') {
                        op1 = expression[k];
                        break;
                    }
                }

                switch (op1) {
                    case '+':
                        return calculateTerm(expression.substr(0, k)) + calculateExpression(expression.substr(k + 1, expression.length()));
                    case '-':
                        return calculateTerm(expression.substr(0, k)) - calculateExpression(expression.substr(k + 1, expression.length()));
                    default:
                        return calculateTerm(expression);
                }
            }
            
            else if(expression[i] == '(' || ( expression[i + 1] == '(' && (int(expression[i] == 42 || int(expression[i] == 47 || int(expression[i] == 43) || int(expression[i] == 45))))))
            {
                if(int(expression[i] == 42 || int(expression[i] == 47) || int(expression[i] == 43) || int(expression[i] == 45) ))
                {
//                    cout << "Neeraj" << endl;
                    first_expression = expression.substr(0, i);
                    op2 = expression[i];
                }
                
                for(int k = i + 1; expression[k] != '\0'; k++)
                {
                    if(expression[k] == ')')
                    {
                        if(op2 == '\0')
                        {
                            //    cout << " inside if" << endl;
                            first_expression = expression.substr(k - 1, expression.length());
                            op2 = expression[k+1];

                           // cout << first_expression << "Nee"<< endl;
                        }
                        //cout << "Outside If" << endl;
                        rest_expression = expression.substr(i+1, k);
                        
                        switch(op2)
                        {
                            case '*': return calculateTerm(first_expression) * calculateExpression(rest_expression);
                            case '/': return calculateTerm(first_expression) / calculateExpression(rest_expression);
                            case '+': return calculateTerm(first_expression) + calculateExpression(rest_expression);
                            case '-': return calculateTerm(first_expression) - calculateExpression(rest_expression);
                            default: return calculateExpression(rest_expression);
                        }
                    }
                }
                op2 = '\0';
            }
            else {
                cout << "hi" << endl;
                rest_expression = expression.substr(i + 1, expression.length());
                op = expression[i];
                first_expression += expression[i-1];
                break;
            }
            // break;
        }
        first_expression += expression[i];

    }

    /*
    cout << atof(first_expression.c_str()) << endl;
    cout << op << endl;
    cout << rest_expression << endl;
     */

    if (op != '\0') {
        switch (op) {
            case '+': return atof(first_expression.c_str()) + calculateExpression(rest_expression);
            case '-': return atof(first_expression.c_str()) - calculateExpression(rest_expression);
        }
    }
    else return atof(first_expression.c_str());

    //return 1;
}

double Calculator::calculateTerm(string expression) {
     cout << "Inside calculate Term" << endl;
     cout << expression << endl;


    //cout << expression << endl;

    string first_term = "", rest_term;
    char op = '\0';

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '/') {
            op = expression[i];
            rest_term = expression.substr(i + 1, expression.length());
            break;
        }
        else if(expression[i] == '(')
            {
                for(int k = i + 1; expression[k] != '\0'; k++)
                {
                    if(expression[k] == ')')
                    {
                        rest_term = expression.substr(i+1, k -1);
                        return calculateExpression(rest_term);
                    }
                    else if(expression[k] == '(')
                    {
                        i = k;
                    }
                }
            }
        first_term += expression[i];

    }

    if (op != '\0') {
        switch (op) {
            case '*': return atof(first_term.c_str()) * calculateTerm(rest_term);
            case '/': return atof(first_term.c_str()) / calculateTerm(rest_term);
        }
    }
    else return atof(first_term.c_str());

    return calculateFactor(expression);
}

double Calculator::calculateFactor(string expression) {
    // cout << "Inside calculate Factor" << endl;
    // cout << expression << endl;

    string first_factor = "", rest_factor = "";
    char op = '\0';

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            op = expression[i];
            rest_factor = expression.substr(i + 1, expression.length());
            break;
        }
        first_factor += expression[i];
    }

    //cout << first_factor << endl;
    // cout << op << endl;

    if (op != '\0') {
        return calculateExpression(rest_factor);

    }
    else
        return atof(first_factor.c_str());

    //return 1;
}