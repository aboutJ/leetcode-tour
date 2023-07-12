#include "header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        for(int i = 0;i < intervals.size();i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(!res.size() || res.back()[1] < left) {
                res.push_back({left, right});
            } else {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};

int main() {}