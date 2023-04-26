# Header File for Arithmetic Expressions

## Introduction

A header file written in C language for interconversion and evaluation of prefix, postfix and infix expressions.

## Features

The header file includes:

- 4 types of evaluation functions
- 6 types of conversion functions
- And, 8 auxiliary functions

## Run Locally

To run the project locally,

1. Clone the project

```bash
git clone https://github.com/Fredorixo/arithmetic-expressions.git
```

2. Go to the project directory

```bash
cd arithmetic-expressions
```

3. To compile your main.c file, run the following command in your terminal

```bash
gcc main.c stack.c arithexp.c aux_func.c
```

This will include **stack.c**, **arithexp.c** and **aux_func.c** source files that contain the implementations of **stack.h** and **arithexp.h** header files.

4. Run your generated executable file

```bash
.\a.exe
```
## Usage/Examples

A **main.c** file is included in the project which contains the usage of all the functions.

Make sure to always use `CheckUnary()` first before using the any of the converting or evaluating functions. 

Before reusing a char array with a stored expression, make sure to empty it.

### Expression Conversion

```c
#include "arithexp.h"

// For storing the result
char resultantExpression[200] = "";
char prefixExpression[200] = "";

CheckUnary("Your Arithmetic Expression", resultantExpression);
InfixToPrefix(resultantExpression, prefixExpression);
PrintString(resultantExpression);
```

### Expression Evaluation

```c
#include "arithexp.h"

// For storing the result
char resultantExpression[200] = "";

CheckUnary("Your Arithmetic Expression", resultantExpression);
EvaluateUsingPostfix(resultantExpression);
PrintString(resultantExpression);
```