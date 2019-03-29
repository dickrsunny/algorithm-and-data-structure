/*
1. Two Sum

Given an array of integers, return indices of
 the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one
 solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */


#include <map>
#include <vector>

using namespace std;


class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_map;
        vector<int> res = {-1, -1};
        for (int i=0; i<nums.size(); i++) {
            if (not (num_map.find(target - nums[i]) != num_map.end())) {
                num_map[nums[i]] = i;
            }
            else {
                res = {num_map[target-nums[i]], i};
                return res;
            }
        }

        return res;
    }
};
