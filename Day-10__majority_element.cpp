/*
 * DATE: 2026-11-03
 *
 * PROBLEM LINK: https://leetcode.com/problems/majority-element/description/
 * PROBLEM STATEMENT:Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * 1. learned the boyer-moore voting algorithm
 * 2. understoodt how to find a majority element without sorting the array
 * 3. Learned how different elements can can each other's votes
 * 4. understood how to maintain a candidate and its frequency using two variables
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {

            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        return candidate;
    }
};