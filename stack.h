/*
A program to implement a stack for integers in C using an array.

For any data type, BaseType, we define an abstract data type Stack of BaseType.
The possible values of this type are sequences of items of type BaseType
(including the sequence of length zero). The operations of the ADT are:

InitStack   : Initializes the stack for usage.
Push(x)     : Adds an item, x, of type BaseType to the stack; that is, modifies
              the value of the stack by appending x to the sequence of items that is
              already on the stack. Returns the item if successful otherwise NULL.
Pop         : Removes an item from the stack and returns that item. The item removed is
              the one that was added most recently by the push operation. It is an
              error to apply this operation to an empty stack. Returns the item if successful otherwise NULL.
makeEmpty   : Removes all items from the stack. No return value.
isEmpty     : Returns a value of type boolean, which is true if the stack contains no items
              and is false if there is at least one item on the stack.
isFull      : Returns a value of type boolean, which is true if the stack cannot store more
              elements else is false.
Top         : This function returns the top most (last in element of the stack). Does not remove
              the element from the stack.
Size        : Returns the size of the stack.

Constraints on the implementation
1. Arrays are of fixed size.
2. Re-sizing of array not to be implemented.
3. Size of array to be fixed at the time of compilation.
*/

#ifndef __STACK__
#define __STACK__

#define MAX_SIZE_STACK 256

typedef struct STACK{
    char* D[MAX_SIZE_STACK]; //The array to store the data
    int T;           // The index of the topmost place utilized till now
} STACK;

void    InitStack(STACK *s);
int     isFull(STACK *s);
int     isEmpty(STACK *s);
void    makeEmpty(STACK *s);
char*   Push(STACK *s, char *x); //NULL on error else address of the element in the stack
char*   Pop(STACK *s); //NULL on error else address of the popped variable
char*   Top(STACK *s); // NULL on error else address of the element in the stack
int     Size(STACK *s);
void    PrintStack(STACK* s);
#endif // __STACK__