/*
 * DATE: 2026-11-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * PROBLEM STATEMENT: Given a string `s`, find the length of the **longest** **substring** without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

**Example 2:**
Input: s = "bbbbb" 
Output: 1
Explanation: The answer is "b", with the length of 1.&#x20;

Example 3:
Input: s = "pwwkew" 
Output: 3 
Explanation: The answer is "wke", with the length of 3. Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.&#x20;

**Constraints:**
 0 <= s.length <= 105`
s consists of English letters, digits, symbols and spaces.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: substring must contain continuous characters, whereas a subsequence does not.
Sliding Window: Instead of checking every possible substring, maintain a window and expand or shrink it.
 left and right define the current window.
Duplicate Handling: When a duplicate appears, shrink the window from the left.
Hash Set: unordered_set helps detect duplicates efficiently.
 The current window length is right - left + 1.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            // Remove duplicate characters
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            // Insert current character
            st.insert(s[right]);

            // Calculate window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
