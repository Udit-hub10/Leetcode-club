/*
 * DATE: 2026-10-30
 *
 * PROBLEM LINK: https://leetcode.com/problems/product-of-array-except-self/description/
 * PROBLEM STATEMENT:Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

 Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
Constraints:
2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: 
 * 1. Array taversal
 * 2. Learn how to handle array containing zero and negative number
 * 3. learn prefix products and suffix product using a single variable
 * 4. understood how to solve multiplicatin problem without 
 *  using the division operator
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        //store left multiplication
        vector<int> left(n);

        //store right multiplication
        vector<int> right(n);

        //left product
        left[0]=1;

        for(int i =1; i<n; i++){
            left[i] = left[i-1] *nums[i-1];
        }

        //right product
        right[n-1] = 1;
        for(int i = n-2; i>= 0; i--){
            right[i] =right[i +1] *nums[i +1];
        }

        //calculate answer
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};