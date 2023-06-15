#include "header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator it = nums.end();
        for(int i = nums.size() - 1;i > 0;i--) {
            it--;
            if(nums[i] > nums[i-1]) {
                sort(it, nums.end());
            }
            for (int j = i;j < nums.size();j++) {
                if(nums[i-1] < nums[j]) {
                    int tmp = nums[i-1];
                    nums[i-1] = nums[j];
                    nums[j] = tmp;
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};

/**
 * 1. 首先找到swap的位置，就是两个升序的数，前面那个就是swap位置
 * 2. swap位置后面的数 整体进行升序排列
 * 3. swap跟后面新排序好的数中第一个比swap位置大的数进行交换
*/

int main() {
    vector<int> nums = {3, 2, 1};
    Solution s;
    s.nextPermutation(nums);
    for (int i = 0; i < 3; i++)
    {
        cout << nums[i] << endl;
    }
    
}