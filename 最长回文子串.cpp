#include "header.h"

// 中心扩散法
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = -1;
        int index = 0;
        for(int i = 0;i < s.size();i++) {
            int left = i - 1;
            int right = i + 1;
            int len = 1;
            while(left >= 0 && s[i] == s[left]) {
                left--;
                len++;
            }

            while(right < s.size() && s[i] == s[right]) {
                right++;
                len++;
            }

            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
                len += 2;
            }

            if(maxLen < len) {
                maxLen = len;
                start = ++left;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    string s = "babad";
    Solution solution;
    solution.longestPalindrome(s);
    return 0;
}