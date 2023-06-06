#include "header.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxVal = nums[0];

        for(int& num : nums) {
            curSum = max(curSum + num, num);
            maxVal = max(curSum, maxVal);
        }
        return maxVal;
    }
};

int main() {
    return 0;
}