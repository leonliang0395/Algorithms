/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (m.find(diff) != m.end()) {
                result.push_back(m[diff]);
                result.push_back(i);
                return result;
            } else {
                m[nums[i]] = i;
            }
        }
        return result;
    }
};

