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
public:
    int sumNumbers(TreeNode* root) {
      return dfs(root, 0);
    }

    int dfs(TreeNode* node, int preSum) {
      if(node == nullptr) {
        return 0;
      }

      preSum = preSum * 10 + node->val;

      if(node->left == nullptr && node ->right == nullptr) {
        return preSum;
      }
      return dfs(node->left, preSum) + dfs(node->right, preSum);
    }
};

int main() {}