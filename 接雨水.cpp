#include "header.h"

// 1.0 没有任何优化的暴力解法
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
        
//         for(int i = 1;i < height.size() - 1;i++) {
//             int l_max = 0, r_max = 0;
//             for(int j = i;j >= 0;j--) {
//                 l_max = max(l_max, height[j]);
//             }

//             for(int k = i;k < height.size();k++) {
//                 r_max = max(r_max, height[k]);
//             }

//             res += min(l_max, r_max) - height[i];
//         }
//         return res;
//     }
// };

// 2.0 优化暴力解法
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        
        vector<int> l_max(n);  // 第i位置左边的最大值包括自身
        vector<int> r_max(n);  // 第i位置右边的最大值包括自身

        l_max[0] = height[0];
        r_max[n-1] = height[n-1];

        for(int i = 1;i < n;i++) {
            l_max[i] = max(height[i], l_max[i-1]);
        }

        for(int i = n-2; i >= 0;i--) {
            r_max[i] = max(height[i], r_max[i+1]);
        }

        for(int i = 0;i < n;i++) {
            res += min(l_max[i], r_max[i]) -height[i];
        }
        return res;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(height) << endl;
}
