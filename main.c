#include <stdio.h>                              // For printf()
#include <string.h>                             // For strcpy()
#include "arithexp.h"

int main(void) {

    char Main_Expression[200] = "(- 2.9)", Expression[200] = "", Result[200] = "", Conclusion[200] = "";


    // 1. String with only Unary Operators

    printf("1. String with only Unary Operators--------------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));


    // 2. String with only Binary Operators

    strcpy(Main_Expression,"(2.5 + 5.5 * 2.0 + 5.2)");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n2. String with only Binary Operators-------------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));


    // 3. String with both Unary & Binary Operators

    strcpy(Main_Expression,"(2.9 + + 5.5 * 2.0 + - 5.2)");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n3. String with both Unary & Binary Operators-----------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));


    // 4. String with Variables

    strcpy(Main_Expression,"(A + B * C + D)");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n4. String with Variables-------------------------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);


    // 5. String with Numbers

    strcpy(Main_Expression,"[10 + 3 * 5 / (16 - 4)]");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n5. String with Numbers---------------------------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));


    // 6. String with only Exponentiation Operator

    strcpy(Main_Expression,"(4 ^ 3 ^ 2)");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n6. String with only Exponentiation Operator------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));


    // 7. String with Complicated Expression

    strcpy(Main_Expression,"(1 + 2 - 3 * 4 + 9 / 6 * 4 - 2 ^ 5 + -6 * 2)");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n7. String with Complicated Expression------------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));


    // 8. String without Brackets

    strcpy(Main_Expression,"-29.5 + 52.6 * 2.4 + 3.6");
    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\n\n8. String without Brackets-----------------------------------------\n");
    CheckUnary(Main_Expression,Expression);
    
    printf("\nInfix Expression---------------------------------------------------\n");
    PrintString(Expression);

    printf("\n\nPostfix Expression-------------------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PrintString(Result);
    
    Result[0] = '\0';                          // Emptying String Result

    printf("\n\nPrefix Expression--------------------------------------------------\n");
    InfixToPrefix(Expression,Result);
    PrintString(Result);

    printf("\n\nPrefix to Postfix Conversion---------------------------------------\n");
    PrefixToPostfix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Prefix Conversion---------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToPrefix(Result,Conclusion);
    PrintString(Conclusion);

    Result[0] = '\0';                           // Emptying String Result

    printf("\n\nPrefix to Infix Conversion-----------------------------------------\n");
    PrefixToInfix(Conclusion,Result);
    PrintString(Result);

    Result[0] = '\0';                           // Emptying String Result
    Conclusion[0] = '\0';                       // Emptying String Conclusion

    printf("\n\nPostfix to Infix Conversion----------------------------------------\n");
    InfixToPostfix(Expression,Result);
    PostfixToInfix(Result,Conclusion);
    PrintString(Conclusion);

    printf("\n\nEvaluating an Infix Expression using Postfix Expression------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    printf("\n\nEvaluating an Infix Expression using Prefix Expression-------------\n");
    printf("%lf",EvaluateUsingPostfix(Expression));

    return 0;
}