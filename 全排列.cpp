#include "header.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> choice;
        backTrace(res, nums, choice, used);
        return res;
    }

    void backTrace(vector<vector<int>>& res, vector<int>& nums, vector<int>& choice, vector<bool>& used) {
        if(choice.size() == nums.size()) {
            res.emplace_back(choice);
        }

        for(int i = 0;i < nums.size();i++) {
            if(!used[i]) {
                used[i] = true;
                choice.emplace_back(nums[i]);
                backTrace(res, nums, choice, used);
                used[i] = false;
                choice.pop_back();
            }
        }
    }
};

int main() {

    return 0;
}

