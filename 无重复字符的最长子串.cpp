#include "header.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxR = 0;

        map<char, int> charMap;

        while(right < s.length()) {
            char c_r = s[right++];
            if (charMap[c_r]) {
                charMap[c_r]++;
            } else {
                charMap[c_r] = 1;
            }

            while(charMap[c_r] > 1) {
                char c_l = s[left++];
                charMap[c_l]--;
            }
            maxR = max(maxR, right - left);
        }
        return maxR;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}