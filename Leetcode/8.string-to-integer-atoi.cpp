/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution {
public:

    /* 
        Empty String
        String with just spaces
        String with spaces in front
        String with spaces in back
        String with just words
        String with just words and one sign
        String with words in front
        String with words in back
        String with no sign
        Number is too big
        Number is too small
     */
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }

        // Loop through str until you find a sign
        int x = 0;
        int digitStart = 0;
        int negative = 1;
        while(x < str.length()) {
            if (str[x] == '-') {
                negative = -1;
                digitStart = x + 1;
                break;
            }
            if (str[x] == '+') {
                digitStart = x + 1;
                break;
            }
            if (isdigit(str[x])) {
                digitStart = x;
                break;
            }
            if (str[x] != ' ') {
                return 0;
            }
            ++x;
        }

        long result = 0;
        int i = digitStart;
        while (i < str.size() && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            if (result > std::numeric_limits<int>::max()) {
                if (negative == -1) {
                    return std::numeric_limits<int>::min();
                } else {
                    return std::numeric_limits<int>::max();
                }
            }
            ++i;
        }
        result *= negative;

        return result;
    }
};

