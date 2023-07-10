#include "header.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
  int maxLen = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
      dfs(root);
      return maxLen;
    }

    int dfs(TreeNode* node) {
      if(node == nullptr) {
        return 0;
      }

      int leftNum = max(dfs(node->left), 0);
      int rightNum = max(dfs(node->right), 0);

      int curVal = leftNum + rightNum + node->val;

      maxLen = max(curVal, maxLen);

      return node->val + max(leftNum, rightNum); 
    }
};

int main() {

}