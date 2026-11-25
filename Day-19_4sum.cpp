./*
 * DATE: 2026-11-25
 *
 * PROBLEM LINK: https://leetcode.com/problems/4sum/description/
 * PROBLEM STATEMENT:
 * 
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:Learned how to extend 3Sum into 4Sum.
 * Understood how to fix two elements and search for the remaining two.
 * Learned duplicate elimination at multiple levels.
 * Understood why long long is necessary.
 * Improved problem-solving from O(n⁴) brute force to O(n³).
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i] +
                                    nums[j] +
                                    nums[left] +
                                    nums[right];

                    if (sum == target) {

                        ans.push_back({
                            nums[i], nums[j],
                            nums[left], nums[right]
                        });

                        left++;
                        right--;

                        // Skip duplicate left elements
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // Skip duplicate right elements
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }

                    else if (sum < target) {
                        left++;
                    }

                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};