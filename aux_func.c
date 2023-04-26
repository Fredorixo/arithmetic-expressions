// Implements all the Auxiliary Functions
#include <stdio.h>                              // For printf()
#include <string.h>                             // For strcpy() , strlen() , strncat() , strcat() , strrev()
#include <math.h>                               // For pow()
#include "arithexp.h"

char  *CheckUnary(char *x, char *y) {

    int size = strlen(x);
    strcpy(y,x);

    RemoveSpaces(y);                            // For removing spaces from the given string
    
    for(int i=0; i<size; i++) {

        // Unary Operators being first in the Expression

        if(y[0] == '-' || y[0] == '+') {
            
            if(y[0] == '-') {
                y[0] = '#';
            }

            else if(y[0] == '+') {
                y[0] = '@';
            }

            // Unary Operator after another Unary Operator

            if(y[i+1] == '-') {
                y[i+1] = '#';
            }

            else if(y[i+1] == '+') {
                y[i+1] = '@';
            }
        }

        // Unary Operator after opening brackets

        else if(y[i] == '(' || y[i] == '{' || y[i] == '[') {

            if(y[i+1] == '+') {
                y[i+1] = '@';
            }

            else if(y[i+1] == '-') {
                y[i+1] = '#';
            }
        }

        // Unary Operators after a Binary Operator

        else if((y[i] == '+' || y[i] == '-') || (y[i] == '*' || y[i] == '/') || y[i] == '^') {

            if(y[i+1] == '+') {
                y[i+1] = '@';
            }

            else if(y[i+1] == '-') {
                y[i+1] = '#';
            }
        }

        // Unary Operators after another Unary Operator

        else if(y[i] == '@' || y[i] == '#') {
            
            if(y[i+1] == '+') {
                y[i+1] = '@';
            }

            else if(y[i+1] == '-') {
                y[i+1] = '#';
            }
        }
    }

    Separator(y);
    return y;
}

void  FormatString(char *x, char *y) {

    int size = strlen(x);

    for(int i=0; i<size; i++) {

        // For Operators 

        if((x[i] == '+' || x[i] == '-') || (x[i] == '*' || x[i] == '/') || (x[i] == '^' || x[i] == '(') || 
           (x[i] == '@' || x[i] == '#') || (x[i] == '[' || x[i] == '{')) {
            
            strncat(y,&x[i],1);
            strcat(y," ");
        }

        // For Separators

        else if(x[i] == ',') {

            strcat(y," ");
        }

        // For Operands

        else {
            strncat(y,&x[i],1);
        }
    }
}

void  PrintString(char *x) {

    char y[200] = "";

    FormatString(x,y);

    printf("%s",y);
}

double Operate(double a, double b, char x) {

    switch (x) {

        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        case '^':
            return pow(a,b);

        case '@':
            return a + b;

        case '#':
            return b - a;

    }
}

char  *RemoveSpaces(char *x) {

    int count = 0;
    int size = strlen(x);

    for(int i=0; i<size; i++) {
        x[count] = x[i];

        if(x[i] != ' ') {
            count++;
        }
    }

    x[count] = '\0';

    return x;
}

char  *makeBracketsProper(char *x) {

    int size = strlen(x);

    for(int i=0; i<size; i++) {

        // For Opening Brackets

        if(x[i] == ')') {
            x[i] = '(';
        }

        else if(x[i] == ']') {
            x[i] = '[';
        }

        else if(x[i] == '}') {
            x[i] = '{';
        }

        // For Closing Brackets

        else if(x[i] == '(') {
            x[i] = ')';
        }

        else if(x[i] == '[') {
            x[i] = ']';
        }

        else if(x[i] == '{') {
            x[i] = '}';
        }
    }

    return x;
}

char  *ReverseString(char *x) {

    char y[200] = "";                           // Declares an Empty String
    char C[15] = "";

    int size = strlen(x);

    for(int i=size-1; i>=0; i--) {

        // For Operators

        if((x[i] == '+' || x[i] == '-') || (x[i] == '*' || x[i] == '/') || x[i] == '^' || (x[i] == '@' || x[i] == '#')) {

            if(C[0] != '\0') {
                strcat(y,strrev(C));            // Concatenate the Reverse of C
                C[0] = '\0';                    // To empty the String C
            }

            strncat(y,&x[i],1);                 // Adding the Operator to the String

            x[i] = '\0';                        // Removing Elements as we go on Parsing from the Original String
        }

        // For Operands

        else {

            // For The separator ','

            if(x[i] == ',') {
                if(x[i+1] != '\0') {
                    
                    strcat(y,strrev(C));
                    C[0] = '\0';                // To empty the String C

                    x[i+1] = '\0';              // Removing Elements as we go on Parsing
                                                // Retaining the Separator
                }
            }

            strncat(C,&x[i],1);
        }
    }

    strcpy(x,y);
    return x;
}

char  *Separator(char *x) {

    char y[200] = "";
    char C[15] = "";

    int size = strlen(x);

    for(int i=0; i<size; i++) {

        // For Operators

        if((x[i] == '(' || x[i] == '[') || (x[i] == '+' || x[i] == '-') || (x[i] == '*' || x[i] == '/') || (x[i] == '^' || x[i] == '{') || 
           (x[i] == '@' || x[i] == '#') || (x[i] == ')' || x[i] == ']') || x[i] == '}') {

            if(C[0] != '\0') {
                strcat(y,C);
                strcat(y,",");
                C[0] = '\0';                    // Emptying the String C
            }

            strncat(y,&x[i],1);
        }

        // For Operands

        else {
            strncat(C,&x[i],1);                 // Copying characters from String Y into String X
        }
    }

    // Pushing Separator ',' in case an operand is left
    
    if(C[0] != '\0') {
        strcat(y,C);
        strcat(y,",");
        C[0] = '\0';                            // Emptying the String C
    }

    strcpy(x,y);
    return x;
}