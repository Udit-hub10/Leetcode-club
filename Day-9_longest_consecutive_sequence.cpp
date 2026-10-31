/*
 * DATE: 2026-10-31
 *
 * PROBLEM LINK: https://leetcode.com/problems/longest-consecutive-sequence/description/
 * PROBLEM STATEMENT:Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3
 

Constraints:
0 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:learn how to store unique element and search efficiently
 * find() help check whether an element exists in avg O(1) time
 * 
 * learn how to find continuous number using a while loop
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        // Step 1: Insert all elements into set
        for (int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        // Step 2: Check every element
        for (int num : st) {

            // Check if num is the starting point
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int count = 1;

                // Step 3: Find consecutive numbers
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};


