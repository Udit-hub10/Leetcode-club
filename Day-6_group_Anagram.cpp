/*
 * DATE: 2026-10-28
 *
 * PROBLEM LINK: https://leetcode.com/problems/group-anagrams/description/
 * PROBLEM STATEMENT:Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 10^0
strs[i] consists of lowercase English letters.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: unordered_map,
 * string key, character traversal,Type Conversion,
 * Frequency Counting, Time & Space Complexity:-O(n.k)time
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> count(26, 0);  //26 alphabet and intializing with 0

            for (char c : s) {
                count[c - 'a']++;  //updation of count with each aphabet
            }

            string key = "";

            for (int i : count) {
                key += "#";   //key me separator add kro
                key += to_string(i);  //freq ko key me add kro
            }

            mp[key].push_back(s);  //map me string store karna
        }

        vector<vector<string>> ans;

        for (auto &p : mp) {   //map ke group ko ans me copy karna
            ans.push_back(p.second);
        }

        return ans;
    }
};