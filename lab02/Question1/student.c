// Question1/Student.c
// ------------------------------------------------------------
// cS Lab - Valid Parentheses (STAcK PRAcTIcE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.


    if (s == NULL) {
        return false;
    }

    if (strlen(s) % 2 == 1) {
        return false;
    }

    if (strlen(s) == 0) {
        return true;
    }

    char stack[strlen(s)];
    size_t top = 0;
    size_t i;


    for (i = 0; i < strlen(s); i++) {

        char c = s[i];

        if (c ==  '(' || c ==  '{' || c ==  '[') {
            stack[top] = c;
            top++;
        }

        else {
            if (top == 0)
            return false;

            char open = stack[top - 1];

            if ((c == ')' && open == '(') || (c == ']' && open == '[') || (c == '}' && open == '{')) {
                top--;
            
            } else {
                return false;
            }
        }
        
    }



    
    //(void)s; // remove after implementing
    return top == 0; // placeholder
}
