/*
 * DATE: 2026-10-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/contains-duplicate/description/
 * PROBLEM STATEMENT:
 *          Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true 

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * 
 * To insert elements in hashSet,and how it use to 
 * know if the array contains duplicate or not..
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    //create hashset to store integer
    unordered_set<int> intSet;

    //Iterate over each element

    for(int num: nums){
        //check the number in hashset
        if(intSet.contains(num))
        return true;

        // add the number to hashset
        intSet.insert(num);

    }
    return false;
}
        
};