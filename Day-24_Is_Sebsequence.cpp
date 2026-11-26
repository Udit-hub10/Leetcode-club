/*
 * DATE: 2026-11-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/is-subsequence/description/
 * PROBLEM STATEMENT: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 
Constraints:
0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
- An empty string is always a subsequence of another string.Using two pointers to traverse strings.
Checking i == s.length() tells us whether all characters have been matched.Traversing strings until a condition is satisfy
The first pointer moves only when characters match.Handling empty strings and different string lengths.
We don't need to create another string or vector to solve this problem.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {

            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return i == s.length();
    }
};
