/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        int bestLength = 1;
        int resultStart = 0;
        int resultEnd = 0;

        // for each element, you're going to expand left and right and keep going until palindrome breaks.
        for (int i = 1; i < s.size(); ++i) {
            // we start at 1 because the middle of the palindrome can't be the first or last element

            // check for palindromes of even size
            int left = i - 1;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                // check if the current length of this sub string is greater than currentMax
                if (right - left + 1 > bestLength) {
                    bestLength = right - left + 1;
                    resultStart = left;
                    resultEnd = right;
                }
                --left;
                ++right;
            }

            // check for palindromes of odd size
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > bestLength) {
                    bestLength = right - left + 1;
                    resultStart = left;
                    resultEnd = right;
                }
                --left;
                ++right;
            }

        }

        return s.substr(resultStart, (resultEnd - resultStart + 1));
    }
};

