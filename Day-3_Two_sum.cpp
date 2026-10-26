/*
 * DATE: 2026-10-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/two-sum/description/
 * PROBLEM STATEMENT:
 * You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation:
The sum of nums[0] and nums[1] is 2 + 7 = 9, which equals the target. Therefore, the indices [0, 1] are returned.

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation:The sum of nums[1] and nums[2] is 2 + 4 = 6, which equals the target. Therefore, the indices [1, 2] are returned.

Example 3:

Input: nums = [3,3], target = 6

Output: [0,1]

Explanation:

The sum of nums[0] and nums[1] is 3 + 3 = 6, which equals the target. Therefore, the indices [0, 1] are returned.

 

Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * Hashing,searching,Array/vectors,Complement approach
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map <int, int> mpp; //store number and index

     int n = nums.size(); // size of array

     for (int i = 0; i < n ; i++){
        int num = nums[i];
        int moreNeeded = target - num;

        if(mpp.find(moreNeeded) != mpp.end()){  //jo number mujhe chahiye kya wo pahle se h
            return {mpp[moreNeeded],i};
        }
        mpp[num] =i;
     }   
     return {-1, -1};
    }
};