#include "student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

 // TODO: implement

	if (nums2Size <= 0) return;

	int i = m - 1;     //nums1 pointer
	int nums2End = (n == nums2Size) ? n : nums2Size; // end of nums2 arr
	int j = nums2End - 1;             // last element in nums2 (uses nums2Size or n)
	int k = nums1Size - 1;         // last position in nums1 (uses nums1Size)

	while (j >= 0) {
		if (i >= 0 && nums1[i] > nums2[j]) {
			nums1[k--] = nums1[i--];
		} else {
			nums1[k--] = nums2[j--];
		}
	}

}
