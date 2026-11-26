/*
 * DATE: 2026-11-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/longest-palindromic-substring/description/
 * PROBLEM STATEMENT: Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * palindrome can have either an odd or even length.
Every character can be a center of an odd-length palindrome.
Every pair of adjacent characters can be a center of an even-length palindrome.
Two pointers help expand in both directions.
We must check array/string boundaries to avoid out-of-range errors.
We can track the longest palindrome using start and maxLen instead of storing every palindrome.
substr(start, length) helps extract the final answer.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */



class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < s.length() &&
                   s[left] == s[right]) {

                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < s.length() &&
                   s[left] == s[right]) {

                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
