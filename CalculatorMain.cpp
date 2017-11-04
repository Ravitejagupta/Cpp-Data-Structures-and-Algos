/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CalculatorMain.cpp
 * Author: neven1
 *
 * Created on October 31, 2017, 12:00 PM
 */
#include <iostream>
#include <cstdlib>
#include "Calculator.h"

using namespace std;

void removeSpaceFromExpression(string& expression);

/*
 * 
 */
int main(int argc, char** argv) {
    
    //cout << "Main Starts" << endl;
    
    /*string temp = "5 * 10 * (11 * 13) = ";
    removeSpaceFromExpression(temp);
    cout << temp << endl;
    */
    
    string expression;
    
    while(true)
    {
        cout << "Enter the Expression or Enter 'N' to exit the program" << endl;    
        getline(cin, expression);
        
      //  temp = exp;
        
        if(expression == "N" || expression == "n")
            break;
        else
            removeSpaceFromExpression(expression);
    
        Calculator calculate(expression);
        calculate.reset();
    }
    //cout << "Main Ends" << endl;

    return 0;
}

void removeSpaceFromExpression(string& expression)
{
    //cout << "Inside Remove Space Function" << endl;
    
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ' ')
        {
            for(int k = i; expression[k] != '\0'; k++)
            {
                expression[k] = expression[k+1];
            }
           // i++;
        }
        
        if(expression[i] == '=')
        {
            expression[i] = '\0';
        }
    }
    return;
}