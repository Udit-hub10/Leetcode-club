/*
 * DATE: 2026-10-29
 *
 * PROBLEM LINK: https://leetcode.com/problems/top-k-frequent-elements/submissions/2184874256/
 * PROBLEM STATEMENT:Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

Constraints:
1 <= nums.length <= 10^5
-104 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * 1.unordered_map se ye pta lgta hai kaunsa ekemnt kitni baar ayi ho
 * 2.haar baar sort() karna jaruri nhi,freq ki maximum limit input size
 *  se bound hai to bucket use kar skte h
 * 3.pehle freq count kiye fir fre ke basis par top k freq element
 * 4. time complexity: O(n)
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // 1. Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        // 2. Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq) {
            int num = it.first;
            int count = it.second;

            bucket[count].push_back(num);
        }

        // 3. Collect top k frequent elements
        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
