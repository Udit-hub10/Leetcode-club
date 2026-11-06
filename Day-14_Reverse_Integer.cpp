/*
 * DATE: 2026-11-07
 *
 * PROBLEM LINK: https://leetcode.com/problems/reverse-integer/description/
 * PROBLEM STATEMENT:Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 210
 

Constraints:
-231 <= x <= 231 - 1
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:Learned how to extract a last digit from a number using %10
 * Learned how to remove the last digit from a number using /10
 * Understand how to construct a reverse number using reverse = reverse *10 + digit
 * learned how to handle negative integers while reversing the number
 * understand how to handle INT_MAX and INT_MIN constraints to prevent overflow
 * 
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x = x / 10;

            // Check integer overflow
            if (rev > INT_MAX / 10 || 
               (rev == INT_MAX / 10 && digit > 7))
                return 0;

            if (rev < INT_MIN / 10 || 
               (rev == INT_MIN / 10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;
        }

        return rev;
    }
};