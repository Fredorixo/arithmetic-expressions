#ifndef __ARITHEXP__
#define __ARITHEXP__

// Strings used in evaluation functions should not contain variables
// EVALUATING A NOTATION

double EvaluateUsingPostfix(char *x);           // x is an Infix String
double EvaluateUsingPrefix(char *x);            // x is an Infix String
double EvaluatePostFix(char *x);                // x is a Postfix String
double EvaluatePreFix(char *x);                 // x is a Prefix String

// CONVERSIONS FROM ONE NOTATION INTO ANOTHER

char  *InfixToPostfix(char *source, char *destination);
char  *InfixToPrefix(char *source, char *destination);
char  *PostfixToPrefix(char *source, char *destination);
char  *PrefixToPostfix(char *source, char *destination);
char  *PostfixToInfix(char *source, char *destination);
char  *PrefixToInfix(char *source, char *destination);

// AUXILIARY FUNCTIONS

char  *CheckUnary(char *x, char *y);            // Converts the standard infix notation to converted unary representation
void   FormatString(char *x, char *y);          // Add a space after each character in the given string
void   PrintString(char *x);                    // Prints the string after calling the FormatString() function
double Operate(double a, double b, char x);     // Based on the operator performs the operation
char  *RemoveSpaces(char *x);                   // Remove spaces from the given string
char  *makeBracketsProper(char *x);             // Places Brackets appropriately when the string is reversed
char  *ReverseString(char *x);                  // Reverses the Prefix Expression especially for Evaluation Purpose
char  *Separator(char *x);                      // Add a comma ',' as a separator to differentiate between Operands

#endif // __ARITHEXP__