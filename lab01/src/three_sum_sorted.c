#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    if (!nums || !out_i || !out_j || !out_k ||n < 2){
    return 0;
    }

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = i+2; k < n; k++)
            if (nums[i] + nums[j] + nums[k] == 0){
                *out_i = i;
                *out_j = j;
                *out_k = k;
                return 1;
            }
            
        }
    }
    // TODO: implement two sum solution for sorted arrays.

    return 0;
    // implement your code here

    return 0;
}
