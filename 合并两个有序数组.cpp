#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      vector<int> tmp = nums1;
      int i = 0, j = 0;
      int index = 0;
      while(i < m && j < n) {
        if(tmp[i] < nums2[j]) {
          nums1[index] = tmp[i++];
        } else {
          nums1[index] = nums2[j++];
        }
        index++;
      }
      if(i < m) {
        while(i < m) {
          nums1[index++] = tmp[i++];
        }
      }
      if(j < n) {
        while(j < n) {
          nums1[index++] = nums2[j++];
        }
      }
    }
};

int main() {

}