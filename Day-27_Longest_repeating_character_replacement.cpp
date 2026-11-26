/*
 * DATE: 2026-11-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/longest-repeating-character-replacement/description/
 * PROBLEM STATEMENT:You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: Expand the window to explore longer substrings.
 Track how many times each character appears.
 We should convert all other characters into the most frequent character.
 Window Size - Maximum Frequency = Required Replacements.
 If required replacements exceed k, shrink the window.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            // Update character frequency
            freq[s[right] - 'A']++;

            // Find maximum frequency
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Check if replacements exceed k
            while ((right - left + 1) - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
