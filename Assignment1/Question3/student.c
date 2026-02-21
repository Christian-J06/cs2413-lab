#include "student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Find the rightmost non-9 digit
    int i;
    for (i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            break;
        }
    }
    
    // Case 1: If all given digits are 9
    if (i == -1) {
        int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
        if (!result) {
            *returnSize = 0;
            return NULL;
        }
        result[0] = 1;
        for (int j = 1; j <= digitsSize; j++) {
            result[j] = 0;
        }
        *returnSize = digitsSize + 1;
        return result;
    }
    
    // Case 2: Add 1 and find resulting integer
    
    int* result = (int*)malloc(digitsSize * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }
    
    for (int j = 0; j < digitsSize; j++) {
        result[j] = digits[j];
    }
    
    result[i]++; 
    for (int j = i + 1; j < digitsSize; j++) {
        result[j] = 0;
    }
    
    *returnSize = digitsSize;
    return result;
}

