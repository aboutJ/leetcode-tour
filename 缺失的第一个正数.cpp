#include "header.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      map<int, int> hashMap;
      for(int i = 0;i < nums.size();i++) {
        hashMap.insert(pair<int, int>(nums[i], i));
      }
      int res = 1;
      map<int, int>::const_iterator it;
      for(it = hashMap.begin();it != hashMap.end();it++) {
        if(it->first <= 0) {
          res = 1;
        } else if (res == it->first) {
          res = it->first + 1;
        }
      }
      return res;
    }
};

int main() {

}