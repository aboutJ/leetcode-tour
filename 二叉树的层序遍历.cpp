#include "header.h"

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if(root == nullptr) return res;
    queue<TreeNode*> cell;
    cell.push(root);
    while(cell.size() > 0) {
      int cellSize = cell.size();
      vector<int> order;
      while(cellSize-- > 0) {
        TreeNode* node = cell.front();
        order.push_back(node->val);
        cell.pop();
        if(node->left) {
          cell.push(node->left);
        }
        if(node->right) {
          cell.push(node->right);
        }
      }
      res.push_back(order);
    }
    return res;
  }
};

int main()
{
}