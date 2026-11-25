./*
 * DATE: 2026-11-25
 *
 * PROBLEM LINK: https://leetcode.com/problems/valid-palindrome/description/
 * 
 * PROBLEM STATEMENT: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true

Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * Learned the Two Pointer technique.
 * Learned how to handle special characters.
 * Learned case-insensitive comparison.
 * 1. Understood how to optimize space complexity from O(n) to O(1).
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else {
                // Compare characters (case-insensitive)
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }
};
