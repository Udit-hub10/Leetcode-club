/*
 * DATE: 2026-11-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/3sum-closest/description/
 * PROBLEM STATEMENT:You are given an integer array nums of length n and an integer target.
Find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: sorting makes it easier to decide which pointer should move.
Fixing one element converts a three-number problem into a two-pointer problem.
If sum < target, increase the sum by moving left forward.
If sum > target, decrease the sum by moving right backward.
abs(sum - target) measures how close the current sum is to the target.
Always initialize closest with the sum of the first three elements rather than 0.
If the sum exactly matches the target, we can return immediately.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Update closest sum
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    return sum;
                }
            }
        }

        return closest;
    }
};
