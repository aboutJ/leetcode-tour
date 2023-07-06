#include "header.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int i = 0, j = 0;
      for(auto& num : nums) {
        if(num != 0) {
          nums[j++] = num;
        }
      } 

      for(int i = j;i < nums.size();i++) {
        nums[i] = 0;
      }
    }
};

int main() {

}