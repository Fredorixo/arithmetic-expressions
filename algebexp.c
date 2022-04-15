// Implements algebexp.h

#include <stdio.h>                                  // For printf()
#include <string.h>                                 // For strlen() , strcat() , strncat() , strdup() , strrev()
#include <stdlib.h>                                 // For atof() , sprintf()

#include "algebexp.h"
#include "stack.h"                                  // For Pop() , Push() , Top() , InitStack() , makeEmpty() , isEmpty()

double EvaluateUsingPostfix(char *x) {

    char y[200] = "";

    InfixToPostfix(x,y);

    return EvaluatePostFix(y);
}

double EvaluateUsingPrefix(char *x) {
    
    char y[200] = "";

    InfixToPrefix(x,y);

    return EvaluatePreFix(y);
}

double EvaluatePostFix(char *source) {

    STACK S;
    InitStack(&S);

    char C[15] = "";                                // Initialising an empty string
    char *x,*y,*z;

    double a,b,c;

    int size = strlen(source);

    for(int i=0; i<size; i++) {

        // For Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || source[i] == '^') {

            x = Pop(&S);
            y = Pop(&S);

            // Converting strings into double

            a = atof(x);
            b = atof(y);

            c = Operate(b,a,source[i]);

            sprintf(C,"%lf",c);                     // Converts the given double into string and stores it in C String
            z = strdup(C);
            Push(&S,z);
            C[0] = '\0';                            // Empties the C String after adding it into the Stack
        }

        else if(source[i] == '@' || source[i] == '#') {

            x = Pop(&S);

            // Converting strings into double

            a = atof(x);
            c = Operate(a,0,source[i]);

            sprintf(C,"%lf",c);                     // Converts the given double into string and stores it in C String
            z = strdup(C);
            Push(&S,z);
            C[0] = '\0';                            // Empties the C String after adding it into the Stack
        }

        // For Operands

        // When a Separator is Encountered

        else if(source[i] == ',') {

            z = strdup(C);
            Push(&S,z);
            C[0] = '\0';                            // To make the C string empty
        }

        else {
            strncat(C,&source[i],1);
        }

    }

    c = atof(Pop(&S));

    makeEmpty(&S);
    return c;
}

double EvaluatePreFix(char *source) {

    STACK S;
    InitStack(&S);

    char C[15] = "";                                // Initialising an empty string
    char *x,*y,*z;

    double a,b,c;

    int size = strlen(source);

    ReverseString(source);                          // Reversing the String

    for(int i=0; i<size; i++) {

        // For Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || source[i] == '^') {

            x = Pop(&S);
            y = Pop(&S);

            // Converting strings into double

            a = atof(x);
            b = atof(y);

            c = Operate(b,a,source[i]);

            sprintf(C,"%lf",c);                     // Converts the given double into string and stores it in C String
            z = strdup(C);
            Push(&S,z);
            C[0] = '\0';                            // Empties the C String after adding it into the Stack
        }

        else if(source[i] == '@' || source[i] == '#') {

            x = Pop(&S);

            // Converting strings into double

            a = atof(x);
            c = Operate(a,0,source[i]);

            sprintf(C,"%lf",c);                     // Converts the given double into string and stores it in C String
            z = strdup(C);
            Push(&S,z);
            C[0] = '\0';                            // Empties the C String after adding it into the Stack
        }

        // For Operands

        // When a Separator is Encountered

        else if(source[i] == ',') {

            z = strdup(C);
            Push(&S,z);
            C[0] = '\0';                            // To make the C string empty
        }

        else {
            strncat(C,&source[i],1);
        }

    }

    c = atof(Pop(&S));

    makeEmpty(&S);
    return c;
}

char  *InfixToPostfix(char *source, char *destination) {

    STACK S;
    InitStack(&S);

    char *y;

    int size = strlen(source);
    for(int i=0; i<size; i++) {

        // For Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || (source[i] == '(' || source[i] == '^') || 
           (source[i] == '@' || source[i] == '#') || (source[i] == '[' || source[i] == '{')) {

            // Insert the first Bracket / Operator

            if(!Top(&S)) {
                Push(&S,&source[i]);
                continue;
            }

            // Otherwise

            switch (*Top(&S)) {

                case '(': 
                    Push(&S,&source[i]);
                    break;

                case '[': 
                    Push(&S,&source[i]);
                    break;

                case '{': 
                    Push(&S,&source[i]);
                    break;

                case '+':
                    if(source[i] == '+' || source[i] == '-') {
                        y = Pop(&S);
                        strncat(destination,y,1);
                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }
                    break;
                
                case '-':
                    if(source[i] == '+' || source[i] == '-') {
                        y = Pop(&S);
                        strncat(destination,y,1);
                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }
                    break;

                case '*':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '(')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        y = Pop(&S);
                        strncat(destination,y,1);
                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }
                    
                    break;

                case '/':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '(')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        y = Pop(&S);
                        strncat(destination,y,1);
                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }
                    
                    break;

                case '^':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '(')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        while(!((isEmpty(&S) || *Top(&S) == '[') || (*Top(&S) == '{' || *Top(&S) == '(') || 
                                *Top(&S) == '+' || *Top(&S) == '-')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                case '@':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '(')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        while(!((isEmpty(&S) || *Top(&S) == '[') || (*Top(&S) == '{' || *Top(&S) == '(') || 
                                *Top(&S) == '+' || *Top(&S) == '-')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '^') {

                        while(!((isEmpty(&S) || *Top(&S) == '[') || (*Top(&S) == '{' || *Top(&S) == '(') || 
                             (*Top(&S) == '*' || *Top(&S) == '/') || (*Top(&S) == '+' || *Top(&S) == '-') || *Top(&S) == '^')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                case '#':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '(')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        while(!((isEmpty(&S) || *Top(&S) == '[') || (*Top(&S) == '{' || *Top(&S) == '(') || 
                                *Top(&S) == '+' || *Top(&S) == '-')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '^') {

                        while(!((isEmpty(&S) || *Top(&S) == '[') || (*Top(&S) == '{' || *Top(&S) == '(') || 
                             (*Top(&S) == '*' || *Top(&S) == '/') || (*Top(&S) == '+' || *Top(&S) == '-') || *Top(&S) == '^')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                default:
                    break;
            }
        }

        // If a Closing Bracket is Encountered

        else if(source[i] == ')') {
            while(*Top(&S) != '(') {
                y = Pop(&S);
                strncat(destination,y,1);
            }

            Pop(&S);
        }

        else if(source[i] == ']') {
            while(*Top(&S) != '[') {
                y = Pop(&S);
                strncat(destination,y,1);
            }

            Pop(&S);
        }

        else if(source[i] == '}') {
            while(*Top(&S) != '{') {
                y = Pop(&S);
                strncat(destination,y,1);
            }

            Pop(&S);
        }

        // For Operands

        else {
            strncat(destination,&source[i],1);
        }
    }

    // When The Stack isn't Empty since no Brackets were used

    while(!isEmpty(&S)) {
        y = Pop(&S);
        strncat(destination,y,1);
    }

    makeEmpty(&S);
    return destination;
}

char  *InfixToPrefix(char *source, char *destination) {

    STACK S;
    InitStack(&S);

    char *y;

    int size = strlen(source);

    // Reverses the String and makes the appropriate changes

    strrev(source);
    makeBracketsProper(source);                     // For Proper Bracket Replacement

    for(int i=0; i<size; i++) {

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || (source[i] == '(' || source[i] == '^') || 
           (source[i] == '@' || source[i] == '#') || (source[i] == '[' || source[i] == '{')) {

            // Insert the first Bracket / Operator

            if(!Top(&S)) {
                Push(&S,&source[i]);
                continue;
            }

            // Otherwise

            switch (*Top(&S)) {

                case '(': 
                    Push(&S,&source[i]);
                    break;

                case '[':
                    Push(&S,&source[i]);
                    break;

                case '{':
                    Push(&S,&source[i]);
                    break;

                case '+':
                    Push(&S,&source[i]);
                    break;
                
                case '-':
                    Push(&S,&source[i]);
                    break;

                case '*':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }
                    
                    break;

                case '/':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                case '^':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-' ||
                                *Top(&S) == '*'|| *Top(&S) == '/')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                case '@':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-' ||
                                *Top(&S) == '*'|| *Top(&S) == '/')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '^') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-' ||
                                *Top(&S) == '*'|| *Top(&S) == '/' || *Top(&S) == '^')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                case '#':
                    if(source[i] == '+' || source[i] == '-') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-')) {
                            y = Pop(&S);
                            strncat(destination,y,1);
                        }
                        
                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '*' || source[i] == '/') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-' ||
                                *Top(&S) == '*'|| *Top(&S) == '/')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else if(source[i] == '^') {
                        while(!(isEmpty(&S) || *Top(&S) == '(' || *Top(&S) == '[' || *Top(&S) == '{' || *Top(&S) == '+'|| *Top(&S) == '-' ||
                                *Top(&S) == '*'|| *Top(&S) == '/' || *Top(&S) == '^')) {

                            y = Pop(&S);
                            strncat(destination,y,1);
                        }

                        Push(&S,&source[i]);
                        break;
                    }

                    else {
                        Push(&S,&source[i]);
                    }

                    break;

                default:
                    break;
            }
        }

        // If a Closing Bracket is Encountered

        else if(source[i] == ')') {
            while(*Top(&S) != '(') {
                y = Pop(&S);
                strncat(destination,y,1);
            }

            Pop(&S);
        }

        else if(source[i] == ']') {
            while(*Top(&S) != '[') {
                y = Pop(&S);
                strncat(destination,y,1);
            }

            Pop(&S);
        }

        else if(source[i] == '}') {
            while(*Top(&S) != '{') {
                y = Pop(&S);
                strncat(destination,y,1);
            }

            Pop(&S);
        }

        // For Operands

        else {
            strncat(destination,&source[i],1);
        }
    }

    // When The Stack isn't Empty since no Brackets were used

    while(!isEmpty(&S)) {
        y = Pop(&S);
        strncat(destination,y,1);
    }

    // Converting our Original String back to Normal

    strrev(source);
    makeBracketsProper(source);                     // For Proper Bracket Replacement

    makeEmpty(&S);
    return strrev(destination);
}

char  *PostfixToPrefix(char *source, char *destination) {

    STACK S;
    InitStack(&S);

    char C[15] = "";
    char *x,*y,*z;

    int size = strlen(source);

    for(int i=0; i<size; i++) {

        // For Binary Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || source[i] == '^') {

            x = Pop(&S);
            y = Pop(&S);

            strncat(destination,&source[i],1);
            strcat(destination,y);
            strcat(destination,x);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Unary Operators

        else if(source[i] == '#' || source[i] == '@') {

            x = Pop(&S);

            strncat(destination,&source[i],1);
            strcat(destination,x);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Operands

        else {
            strncat(C,&source[i],1);

            // When The Separator is Encountered and if True, is Pushed into the Stack

            if(source[i] == ',') {
                z = strdup(C);
                Push(&S,z);
                C[0] = '\0';                        // Emptying the String C
            }
        }
    }

    strcpy(destination,Pop(&S));

    makeEmpty(&S);
    return destination;
}

char  *PrefixToPostfix(char *source, char *destination) {

    ReverseString(source);
    int size = strlen(source);

    STACK S;
    InitStack(&S);

    char C[15] = "";
    char *x,*y,*z;

    for(int i=0; i<size; i++) {

        // For Binary Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || source[i] == '^') {

            x = Pop(&S);
            y = Pop(&S);
            
            strcat(destination,x);
            strcat(destination,y);
            strncat(destination,&source[i],1);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Unary Operators

        else if(source[i] == '@' || source[i] == '#') {

            x = Pop(&S);

            strcat(destination,x);
            strncat(destination,&source[i],1);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Operands

        else {
            strncat(C,&source[i],1);

            // When The Separator is Encountered and if True, is Pushed into the Stack

            if(source[i] == ',') {
                z = strdup(C);
                Push(&S,z);
                C[0] = '\0';                        // Emptying the String C
            }
        }
    }

    strcpy(destination,Pop(&S));

    makeEmpty(&S);
    return destination;
}

char  *PostfixToInfix(char *source, char *destination) {
    
    STACK S;
    InitStack(&S);

    char C[15] = "";
    char *x,*y,*z;

    int size = strlen(source);

    for(int i=0; i<size; i++) {

        // For Binary Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || source[i] == '^') {

            x = Pop(&S);
            y = Pop(&S);

            strcat(destination,y);
            strncat(destination,&source[i],1);
            strcat(destination,x);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Unary Operators

        else if(source[i] == '@' || source[i] == '#') {

            x = Pop(&S);

            strncat(destination,&source[i],1);
            strcat(destination,x);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Operands

        else {
            strncat(C,&source[i],1);

            // When The Separator is Encountered and if True, is Pushed into the Stack

            if(source[i] == ',') {
                z = strdup(C);
                Push(&S,z);
                C[0] = '\0';                        // Emptying the String C
            }
        }

    }

    strcpy(destination,Pop(&S));

    makeEmpty(&S);
    return destination;
}

char  *PrefixToInfix(char *source, char *destination) {

    ReverseString(source);
    int size = strlen(source);

    STACK S;
    InitStack(&S);

    char C[15] = "";
    char *x,*y,*z;

    for(int i=0; i<size; i++) {

        // For Binary Operators

        if((source[i] == '+' || source[i] == '-') || (source[i] == '*' || source[i] == '/') || (source[i] == '(' || source[i] == '^')) {

            x = Pop(&S);
            y = Pop(&S);

            strcat(destination,x);
            strncat(destination,&source[i],1);
            strcat(destination,y);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Unary Operators

        else if(source[i] == '@' || source[i] == '#') {

            x = Pop(&S);

            strncat(destination,&source[i],1);
            strcat(destination,x);

            z = strdup(destination);                //  Duplicates destination and makes z point to the duplicated string
            destination[0] = '\0';                  //  To empty the String destination

            Push(&S,z);
        }

        // For Operands

        else {
            strncat(C,&source[i],1);

            // When The Separator is Encountered and if True, is Pushed into the Stack

            if(source[i] == ',') {
                z = strdup(C);
                Push(&S,z);
                C[0] = '\0';                        // Emptying the String C
            }
        }
    }
    
    strcpy(destination,Pop(&S));

    makeEmpty(&S);
    return destination;
}
