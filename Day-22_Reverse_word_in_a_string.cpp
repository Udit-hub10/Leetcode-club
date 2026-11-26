/*
 * DATE: 2026-11-26
 *
 * PROBLEM LINK: https://leetcode.com/problems/reverse-words-in-a-string/description/
 * PROBLEM STATEMENT:Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words.
 The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * stringstream automatically ignores leading, trailing and multiple spaces.
 * We can extract individual words without manually checking every character.
 * reverse() can reverse an entire vector using iterators.
 *  We can construct the answer by joining words with a single space.
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Join words with single space
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            if (i > 0) {
                ans += " ";
            }
            ans += words[i];
        }

        return ans;
    }
};