#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9;
        int maxPft = 0;
        for(auto& price : prices) {
            // 找历史最低价格，与历史最低价格求差值
            maxPft = max(maxPft, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return maxPft;
    }
};

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(nums);
    return 0;
}