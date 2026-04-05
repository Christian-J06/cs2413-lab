/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    /* Write your code here */
    
    // Allocate min-heap of size k
    int* heap = (int*)malloc(k * sizeof(int));
    int heapSize = 0;
    
    // Insert all elements into the heap
    for (int i = 0; i < numsSize; i++) {
        if (heapSize < k) {
            // Heap not full, add element
            heap[heapSize] = nums[i];
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (nums[i] > heap[0]) {
            // Current element is larger than min, replace min and heapify down
            heap[0] = nums[i];
            heapifyDown(heap, heapSize, 0);
        }
    }
    
    int result = heap[0];
    free(heap);
    return result;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    /* Write your code here if you use this helper */

    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* heap, int index) {
    /* Write your code here if you use this helper */

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            swap(&heap[index], &heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    /* Write your code here if you use this helper */

    while (1) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        
        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}