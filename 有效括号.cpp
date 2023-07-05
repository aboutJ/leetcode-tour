#include "header.h"

class Solution {
public:
    bool isValid(string s) {
      if(s.size() % 2 != 0) return false;
      stack<char> st;
      for(int i = 0;i < s.size();i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
          st.push(s[i]);
        } else {
          if(st.size() <= 0) return false;
          char top = st.top();
          st.pop();
          if (getCurChar(s[i]) != top) {
            return false;
          }
        }
      }
      if(st.size() > 0) return false;
      return true;
    }

    char getCurChar(char s) {
      if(s == ')') {
        return '(';
      } else if (s == ']') {
        return '[';
      } else if (s == '}') {
        return '{';
      } else {
        return ' ';
      }
    }
};

int main() {
  Solution s;
  cout << s.isValid("([)]");
}