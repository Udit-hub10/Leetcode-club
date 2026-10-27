/*
 * DATE: 2026-10-27
 *
 * PROBLEM LINK: https://leetcode.com/problems/valid-anagram/
 * PROBLEM STATEMENT:Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 10^4
    s and t consist of lowercase English letters.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: string - to access character s.length,s[i]
   Array  :- int count[26] = {0}; se frequency store karna aur array traversal
   Loop :- for loop se characters ko traverse karna aur counts check karna.
   s[i] - 'a' se character ko array index mein convert karna
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m != n) {
            return false;
        }

        int count[26] = {0};

        for (int i = 0; i < m; i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
