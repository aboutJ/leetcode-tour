#include "header.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      string res;

      int i = 0, j = 0, carry = 0;
      while(i < num1.size() || j < num2.size()) {
        int first = 0, second = 0;
        if(i < num1.size()) first = num1[i] - '0';
        if(j < num2.size()) second = num2[j] - '0';
        int sum = (first + second + carry) % 10;
        carry = (first + second + carry) / 10;
        res.append(to_string(sum));
        i++;
        j++;
      }
      if(carry>0) res.append(to_string(carry));
      reverse(res.begin(), res.end());
      return res;
    }
};

int main() {
  Solution s;
  s.addStrings("11", "123");
