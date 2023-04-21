#include "header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(begin(nums), end(nums));
        return nums[size -k];
    }
};

int main() {

    return 0;
}