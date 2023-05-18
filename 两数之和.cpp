#include "header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash = {{nums[0], 0}};
        for(int i = 1;i < nums.size();i++) {
            if(hash.count(target - nums[i]) > 0) {
                return {i, hash[target - nums[i]]};
            } else {
                hash.insert(pair<int, int>(nums[i], i));
            }
        }
        return {-1, -1};
    }
};